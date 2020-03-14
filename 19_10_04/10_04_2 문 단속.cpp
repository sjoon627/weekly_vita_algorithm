#include<iostream>
#include<stack>
using namespace std;
int main() {
	int n, num; cin >> n;
	stack<int> s;
	for (int i = 0; i < 2 * n; ++i) {
		cin >> num;
		if (num > 0)
			s.push(num);
		else {
			if (s.empty() || s.top() != -num) {
				cout << "no";
				return 0;
			}
			s.pop();
		}
	}
	if (s.empty())
		cout << "yes";

	else
		cout << "no";
}
