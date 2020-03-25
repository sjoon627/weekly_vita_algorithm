#include<iostream>
#include<vector>
using namespace std;
int chk[1010];	//방문 여부를 표시 할 배열
vector<int> adj[1010];	//그래프를 저장하는 인접 리스트
void init(){	//방문 표시 초기화
	for(int i = 0; i<1010; ++i)
		chk[i] = 0;
}
int go(int cur){	//방문한 정점의 개수를 세어주는 함수(DFS)
	chk[cur] = 1;
	int res = 1;	//현재 정점을 방문했으므로 결과 + 1
	for(int i = 0; i<adj[cur].size(); ++i){	//인접한 모든 정점 탐색
		int next = adj[cur][i];
		if(!chk[next])	//만약 방문하지 않은 정점이라면
			res += go(next);	//해당 정점을 방문하고 반환받은 값을 결과에 더해줌
	}
	return res;
}
int main(){
	int v, e; cin >> v >> e;
	for(int i = 0; i<e; ++i){
		int from, to; cin >> from >> to;
		adj[from].push_back(to);
	}
	int ans = 0, ansV = 0;
	for(int i = 1; i<=v; ++i){
		init();
		int res = go(i);
		if(res > ans){
			ans = res;
			ansV = i;
		}
	}
	cout << ansV;
}
