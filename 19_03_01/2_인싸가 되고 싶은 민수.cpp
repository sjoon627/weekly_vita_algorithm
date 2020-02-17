#include <iostream>
using namespace std;

int leastFactor(int n) {
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) return i;
	return n;
}
int main() {
	int a, b;
	cin >> a >> b;

	if (a != b) cout << 2;
	else cout << leastFactor(a);

	return 0;
}
