#include<iostream>
#include<vector>
using namespace std;
vector<int> adj[1010];	//�׷����� ������ ���� ����Ʈ
int chk[1010];	//�湮 Ȯ�ο� �迭(-1: �湮 ����, 0,1 : �湮 ��)
//dfs�� ���� �Լ�(s: ���� ����, color: ��ĥ�� ��)
//���� �̺� �׷����� ���ǿ� ���� �ʴ� ������ �ִٸ� false�� ��ȯ
bool go(int s, int color) {
	chk[s] = color;	//���� ������ color�� ��ĥ����
	for (int i = 0; i < adj[s].size(); ++i) {	//���� ������ ����� ��� ���� Ȯ��
		int next = adj[s][i];
		if (chk[next] == -1)	//���� ������ �湮���� ���� �����̶�� �湮
			go(next, color ^ 1);
		else if (color == chk[next])	//���� �̹� �湮�� ���̰�, ���� ������ ���� ���ٸ� false ��ȯ
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
