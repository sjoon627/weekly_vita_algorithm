#include<iostream>
#include<vector>
using namespace std;
vector<int> adj[1010];	//그래프를 저장할 인접 리스트
int chk[1010];	//방문 확인용 배열(-1: 방문 안함, 0,1 : 방문 함)
//dfs를 위한 함수(s: 현재 정점, color: 색칠할 색)
//만약 이분 그래프의 조건에 맞지 않는 정점이 있다면 false를 반환
bool go(int s, int color) {
	chk[s] = color;	//현재 정점애 color를 색칠해줌
	for (int i = 0; i < adj[s].size(); ++i) {	//현재 정점과 연결된 모든 정점 확인
		int next = adj[s][i];
		if (chk[next] == -1)	//다음 정점이 방문하지 않은 정점이라면 방문
			go(next, color ^ 1);
		else if (color == chk[next])	//만약 이미 방문한 점이고, 현재 정점과 색이 같다면 false 반환
			return 0;
	}
	return 1;
}
int main() {
	for(int i = 0; i<1010; ++i)
		chk[i] = -1;
	int v, e;
	cin >> v >> e;
	for (int i = 1; i <= v; ++i)
		adj[i].clear();
	for (int i = 0; i < e; ++i) {
		int from, to;
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	
	if (go(1, 0))
		cout << "yes";
	else
		cout << "no";
}
