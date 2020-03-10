#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long ll;
int n, num, cost[20][20];
int d[1 << 16][16];
const int inf = 1e9;		//답이 될 수 없는 아주 큰 값
int TSP(int cur, int stat) {
	if (stat == (1 << n) - 1)		//모든 지역을 방문한 경우
		return cost[cur][0] ? cost[cur][0] : inf;	//현재 지역에서 출발지(0)로 이동 가능한지
	int& res = d[stat][cur];
	if (res != -1) return res;	//만약 답이 이미 메모되어있으면 답을 리턴
	res = inf;	//답이 메모되어 있지 않은 경우 큰 값으로 답을 초기화
	for (int i = 0; i < n; ++i)		//1 ~ n 모든 지역을 돌며
		if ((stat & (1 << i)) == 0 && cost[cur][i])	//i번째 지역을 방문한적이 없고, 이동 가능하면
			res = min(res, TSP(i, stat | (1 << i)) + cost[cur][i]);	//i번째 지역 방문체크 후 이동
	return res;
}
int main() {
	memset(d, -1, sizeof(d));			//초기 메모를 절대 나올 수 없는 답인 -1로 초기화 해줍니다. 
										//이 함수는 string.h 헤더에 정의되어 있습니다
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> cost[i][j];
	cout << TSP(0, 1);
	return 0;
}
