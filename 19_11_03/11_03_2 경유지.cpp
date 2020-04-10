#include<queue>
#include<algorithm>
#include<iostream>
#include<vector>
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
	int v, e; cin >> v >> e;
	for (int i = 0; i < e; ++i) {
		int from, to, w;
		cin >> from >> to >> w;
		adj[from].push_back({ to, w });
		adj[to].push_back({ from, w });
	}
	int x, t, k; cin >> x >> t >> k;
	vector<int> des(k);
	for (int i = 0; i < k; ++i)
		cin >> des[i];
	vector<int> ans = dijkstra(x);
	int res[2] = { 0 };
	if (k == 2) {	//경유지가 두 개인 경우
		res[0] = ans[des[0]];
		res[1] = ans[des[1]];
		ans = dijkstra(des[0]);
		res[0] += ans[des[1]];
		res[1] += ans[t];
		ans = dijkstra(des[1]);
		res[0] += ans[t];
		res[1] += ans[des[0]];
		res[0] = min(res[0], res[1]);
	}
	else {	//경유지가 한 개인 경우
		res[0] = ans[des[0]];
		ans = dijkstra(des[0]);
		res[0] += ans[t];
	}
	cout << (res[0] < inf ? res[0] : -1);
}
