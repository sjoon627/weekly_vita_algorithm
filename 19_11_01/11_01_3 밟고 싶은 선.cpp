#include<iostream>
#include<vector>
using namespace std;
vector<int> seq;	//Ⱦ�ܺ����� ���¸� �����ϴ� �迭
int n, a;
bool chk[10101];	//�湮 ǥ�ø� �ϱ� ���� �迭
bool go(int s) {
	if (s == n - 1) return 1;	//���� ������ ������ �����ߴٸ� true ��ȯ
	if (chk[s]) return 0;	//�̹� �湮�ߴ� �����̶�� false�� ��ȯ
	chk[s] = 1;	//���� ������ �湮 ǥ��
	for (int i = 1; i <= a; ++i) {	//���� �������κ��� �� �� �ִ� ��� ĭ�� ����
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
