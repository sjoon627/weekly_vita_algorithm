#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int> > vec(N), vec2(2 * N);
	for (int i = 0; i < N; ++i) {
		int a, b, c, d;
		char ch1, ch2;
		cin >> a >> ch1 >> b >> c >> ch2 >> d;
		vec[i] = { a * 100 + b, c * 100 + d };
	}

	sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
		if (a.first != b.first) return a.first < b.first;
		return a.second > b.second;
	});

	for (int i = 0; i < N; ++i) {
		vec2[i * 2] = { vec[i].first, i + 1 };
		vec2[i * 2 + 1] = { vec[i].second, -i - 1 };
	}

	sort(vec2.begin(), vec2.end());

	stack<int> s;
	for (int i = 0; i < 2 * N; ++i) {
		if (vec2[i].second > 0) s.push(vec2[i].second);
		else {
			if (s.top() == -vec2[i].second) s.pop();
			else {
				cout << "No";
				return 0;
			}
		}
	}

	cout << "Yes";

	return 0;
}
