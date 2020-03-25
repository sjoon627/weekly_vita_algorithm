#include<iostream>
#include<vector>
using namespace std;
vector<int> seq;	//횡단보도의 상태를 저장하는 배열
int n, a;
bool chk[10101];	//방문 표시를 하기 위한 배열
bool go(int s) {
	if (s == n - 1) return 1;	//만약 마지막 지점에 도착했다면 true 반환
	if (chk[s]) return 0;	//이미 방문했던 지점이라면 false를 반환
	chk[s] = 1;	//현재 지점에 방문 표시
	for (int i = 1; i <= a; ++i) {	//현재 지점으로부터 갈 수 있는 모든 칸을 조사
		int nx = s + i;
		if (nx < n && seq[nx])
			if(go(nx)) return 1;
	}
	return 0;
}
int main() {
	cin >> n >> a;
	seq.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> seq[i];
	if (go(0)) {
		cout << "yes";
	}
	else {
		cout << "no";
	}
}
