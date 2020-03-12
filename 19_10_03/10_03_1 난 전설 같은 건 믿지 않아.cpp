#include <iostream>
using namespace std;
void go(int cur, int from, int to){
	if(cur == 0) return;
	int next = 6 - to - from;
	go(cur - 1, from, next);
	cout << cur << " " << to << '\n';
	go(cur - 1, next, to);
}
int main() {
	int n, k; cin >> n >> k;
	go(n, 1, k);
}
