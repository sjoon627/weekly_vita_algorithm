#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int main() {
	int d[101010];
	int n;	cin >> n;
	vector<int> price(n);
	memset(d, 0x3f, sizeof(d));	//�迭�� �ʱⰪ�� ���� �ſ� ū ������ �ʱ�ȭ
	for (int i = 0; i < n; ++i) {
		cin >> price[i];
		d[price[i]] = 1;
	}
	int m; cin >> m;
	sort(price.begin(), price.end());	//�Է¹��� �迭�� ����
	for (int i = 1; i <= m; ++i)	//��ġ 1~m���� ��� ���� ������� ����
		for (int j = 0; j < n && price[j] <= i; ++j)	//j�� ȭ���� �������� �۰�, ȭ���� ��ġ�� ���� Ǯ���� �ϴ� ���� i���� �۾ƾ� ��
			d[i] = min(d[i], d[i - price[j]] + 1);
	cout << (d[m] > 100000 ? -1 : d[m]);
}
