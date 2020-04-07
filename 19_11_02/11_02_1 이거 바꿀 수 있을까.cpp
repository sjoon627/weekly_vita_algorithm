#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int main() {
	int d[101010];
	int n;	cin >> n;
	vector<int> price(n);
	memset(d, 0x3f, sizeof(d));	//배열의 초기값을 전부 매우 큰 값으로 초기화
	for (int i = 0; i < n; ++i) {
		cin >> price[i];
		d[price[i]] = 1;
	}
	int m; cin >> m;
	sort(price.begin(), price.end());	//입력받은 배열을 정렬
	for (int i = 1; i <= m; ++i)	//가치 1~m까지 모든 답을 순서대로 구함
		for (int j = 0; j < n && price[j] <= i; ++j)	//j는 화폐의 개수보다 작고, 화폐의 가치는 헌재 풀고자 하는 답인 i보다 작아야 함
			d[i] = min(d[i], d[i - price[j]] + 1);
	cout << (d[m] > 100000 ? -1 : d[m]);
}
