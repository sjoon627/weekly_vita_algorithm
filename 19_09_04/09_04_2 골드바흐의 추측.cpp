#include<iostream>
#include<vector>
using namespace std;
bool p[1010101] = { 1, 1 };
vector<int> prime;
int main() {
	for (int i = 2; i * i <= 1010101; ++i) {
		if (p[i]) continue;
		for (int j = i * i; j < 1010101; j += i)
			p[j] = 1;
	}
	for (int i = 2; i <= 1000000; ++i)
		if (!p[i])prime.push_back(i);

	
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int num; cin >> num;
		int a1, a2, l = 0, r = prime.size() - 1;
		int cnt = 0;
		while (l <= r) {
			int sum = prime[l] + prime[r];
			if (sum == num) {
				a1 = prime[l], a2 = prime[r];
				++l; --r;
			}
			else if (sum < num)
				++l;
			else
				--r;
		}
		cout << a1 << ' ' << a2 << '\n';
	}
}
