#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int n, e = 0; cin >> n;
	vector<int> seq(n);
	for (int i = 0; i < n; ++i) 
		cin >> seq[i];
	sort(seq.begin(), seq.end());
	int ans = 0, cur = 0;
	for(int i = 0; i<seq.size(); ++i){
		if(seq[i] >= cur){
			++cur; ++ans;
		}
	}
	cout << ans;
}
