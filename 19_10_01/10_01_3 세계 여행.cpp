#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long ll;
int n, num, cost[20][20];
int d[1 << 16][16];
const int inf = 1e9;		//���� �� �� ���� ���� ū ��
int TSP(int cur, int stat) {
	if (stat == (1 << n) - 1)		//��� ������ �湮�� ���
		return cost[cur][0] ? cost[cur][0] : inf;	//���� �������� �����(0)�� �̵� ��������
	int& res = d[stat][cur];
	if (res != -1) return res;	//���� ���� �̹� �޸�Ǿ������� ���� ����
	res = inf;	//���� �޸�Ǿ� ���� ���� ��� ū ������ ���� �ʱ�ȭ
	for (int i = 0; i < n; ++i)		//1 ~ n ��� ������ ����
		if ((stat & (1 << i)) == 0 && cost[cur][i])	//i��° ������ �湮������ ����, �̵� �����ϸ�
			res = min(res, TSP(i, stat | (1 << i)) + cost[cur][i]);	//i��° ���� �湮üũ �� �̵�
	return res;
}
int main() {
	memset(d, -1, sizeof(d));			//�ʱ� �޸� ���� ���� �� ���� ���� -1�� �ʱ�ȭ ���ݴϴ�. 
										//�� �Լ��� string.h ����� ���ǵǾ� �ֽ��ϴ�
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> cost[i][j];
	cout << TSP(0, 1);
	return 0;
}
