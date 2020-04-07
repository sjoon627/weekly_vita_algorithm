#include<string.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll d[2][101010];
vector<int> seq;
ll go(int op, int cur ,int prev){
	if(cur == seq.size()) return prev;
	ll & res = d[op][cur];
	if(~res) return res;
	res = min(go(0, cur + 1, 0) + seq[cur] + prev, go(1, cur + 1, 2) + 9 - seq[cur]);
	return res;
}

int main() {
	memset(d, -1, sizeof(d));
	string str; cin >> str;
	for(auto c : str)
		seq.push_back(c - '0');
	cout << min(go(0, 0, 0), go(1, 0, 0));
	return 0;
}
