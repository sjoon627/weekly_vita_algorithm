#include<queue>
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
	int v, e, st;	cin >> v >> e;
	for (int i = 0; i < e; ++i) {
		int from, to, w;
		cin >> from >> to >> w;
		adj[from].push_back({ to, w });
		adj[to].push_back({ from, w });
	}
	cin >> st;
	vector<int> ans = dijkstra(st);
	for (int i = 1; i <= v; ++i) {
		if (ans[i] >= inf)
				ans[i] = -1;
		cout << ans[i] << '\n';
	}
}
