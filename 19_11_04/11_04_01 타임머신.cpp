#include<vector>
#include<iostream>
using namespace std;
struct EDGE {
	int from, to, w;
};
const int inf = 1e8;
vector<EDGE> edge;
bool nCycle = 0;
vector<int> BellmanFord(int v, int s) {
	vector<int> dist(v + 1);
	fill(dist.begin(), dist.end(), inf);
	dist[s] = 0;
	for (int i = 1; i <= v; ++i) {
		for (int j = 0; j < edge.size(); ++j) {
			int from = edge[j].from, to = edge[j].to, w = edge[j].w;
			if (dist[from] != inf && dist[to] > dist[from] + w) {
				dist[to] = dist[from] + w;
				if (i == v) {
					nCycle = 1;
					break;
				}
			}
		}
	}
	return dist;
}
int main() {
	int v, e;
	cin >> v >> e;
	edge.resize(e);
	for (int i = 0; i < e; ++i)
		cin >> edge[i].from >> edge[i].to >> edge[i].w;
	vector<int> ans = BellmanFord(v, 1);
	if (nCycle) 
		cout << "No";
	else {
		cout << "Yes";
	}
}
