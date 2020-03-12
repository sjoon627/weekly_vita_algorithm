#include<vector>
#include<utility>
#include<iostream>
using namespace std;
typedef pair<int, int> P;
vector<int> ans;
void merge(vector<P>& seq, int l, int r) {
	vector<P> tmp;
	int mid = (l + r) / 2;
	int f = l, s = mid + 1;
	while (f <= mid && s <= r) {
		if (seq[f].first <= seq[s].first)
			tmp.push_back(seq[f++]);
		else {
			tmp.push_back(seq[s]);
			ans[seq[s++].second] += mid - f + 1;
		}
	}
	for (; f <= mid; ++f)
		tmp.push_back(seq[f]);
	for (; s <= r; ++s)
		tmp.push_back(seq[s]);
	for (int i = l; i <= r; ++i)
		seq[i] = tmp[i - l];
}

void merge_sort(vector<P>& seq, int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		merge_sort(seq, l, mid);
		merge_sort(seq, mid + 1, r);
		merge(seq, l, r);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ans.clear();
	int n; cin >> n;
	vector<P> seq(n);
	ans.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> seq[i].first;
		seq[i].second = i;
	}
	merge_sort(seq, 0, n - 1);
	for (int i = 0; i<ans.size(); ++i)
		cout << ans[i] << '\n';
}
