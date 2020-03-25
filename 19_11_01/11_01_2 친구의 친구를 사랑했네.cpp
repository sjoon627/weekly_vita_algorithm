#include<iostream>
#include<vector>
using namespace std;
int chk[1010];	//�湮 ���θ� ǥ�� �� �迭
vector<int> adj[1010];	//�׷����� �����ϴ� ���� ����Ʈ
void init(){	//�湮 ǥ�� �ʱ�ȭ
	for(int i = 0; i<1010; ++i)
		chk[i] = 0;
}
int go(int cur){	//�湮�� ������ ������ �����ִ� �Լ�(DFS)
	chk[cur] = 1;
	int res = 1;	//���� ������ �湮�����Ƿ� ��� + 1
	for(int i = 0; i<adj[cur].size(); ++i){	//������ ��� ���� Ž��
		int next = adj[cur][i];
		if(!chk[next])	//���� �湮���� ���� �����̶��
			res += go(next);	//�ش� ������ �湮�ϰ� ��ȯ���� ���� ����� ������
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
