#include<iostream>
#include<string.h>
using namespace std;
int room[303][303];
int d[303][303];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n;
int go(int x, int y){
	int & res = d[x][y];
	if(~res) return res;
	res = 1;
	for(int i = 0; i<4; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(0 <= nx && nx < n && 0 <= ny && ny < n && room[nx][ny] < room[x][y])
			res = max(res, go(x + dx[i], y + dy[i]) + 1);
	}
	return res;
}
int main(){
	memset(d, -1, sizeof(d));
	cin >> n;
	for(int i = 0; i<n; ++i)
		for(int j = 0; j<n; ++j)
			cin >> room[i][j];
	int ans = 0;
	for(int i = 0; i<n; ++i)
		for(int j = 0; j<n; ++j)
			ans = max(ans, go(i, j));
	cout << ans;
}
