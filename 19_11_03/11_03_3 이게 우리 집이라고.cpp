#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
const int VMAX = 20202;
const int inf = 1e8;
struct EDGE {
	int to, w;
};
vector<EDGE> adj[VMAX];
bool operator < (EDGE e1, EDGE e2) {
	return e1.w > e2.w;
}
vector<int> dijkstra(int s) {
	vector<int> ans(VMAX);
	fill(ans.begin(), ans.end(), inf);
	priority_queue<EDGE> q;
	q.push({ s, 0 });
	ans[s] = 0;
	while (q.size()) {
		int cur = q.top().to, d = q.top().w;
		q.pop();
		for (int i = 0; i < adj[cur].size(); ++i) {
			int nextV = adj[cur][i].to, nextD = adj[cur][i].w + d;
			if (ans[nextV] > nextD) {
				ans[nextV] = nextD;
				q.push({ nextV, nextD });
			}
		}
	}
	return ans;
}
int main() {
	int v, e, st, k;	cin >> v >> e;
	for (int i = 0; i < e; ++i) {
		int from, to, w;
		cin >> from >> to >> w;
		adj[from].push_back({ to, w });
		adj[to].push_back({ from, w });
	}
	cin >> st >> k;
	vector<int> ans = dijkstra(st);
	vector<pair<int, int>> tmp;	//i번 정점까지의 거리와 정점 번호를 저장할 배열
	for (int i = 1; i <= v; ++i) 
		tmp.push_back({ ans[i], i });
	sort(tmp.begin(), tmp.end());
	if (tmp[k - 1].first >= inf)
		cout << -1;
	else
		cout << tmp[k - 1].second;
}
