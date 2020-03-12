#include<iostream>
using namespace std;
int board[1212][1212], ans;
void go(int x, int y, int sz) {
	if (sz == 1) {
		++ans; return;
	}
	bool stop = 0;
	int st = board[x][y];
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz; ++j) {
			if (board[i + x][j + y] != st) {
				stop = 1;
				break;
			}
		}
		if (stop) break;
	}
	if (stop) {
		int ns = sz / 2;
		int nx = x + ns;
		int ny = y + ns;

		go(x, y, ns);
		go(nx, y, ns);
		go(x, ny, ns);
		go(nx, ny, ns);
	}
	else
		++ans;
}
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
	go(0, 0, n);
	cout << ans;
}
