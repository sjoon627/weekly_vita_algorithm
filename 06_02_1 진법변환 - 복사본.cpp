#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string str;
	cin >> N >> str;

	for (int i = 2; i <= 16; ++i) {
		int j, sum = 0;

		// i�������� �����ϰ� ���
		for (j = 0; j < str.size(); ++j) {
			int val = str[j] >= 'A' ? str[j] - 'A' + 10 : str[j] - '0';

			// i������ i �̻��� ���� ���� �� ����
			if (val >= i) break;
			sum *= i;
			sum += val;
		}

		if (j == str.size() && sum == N) {
			cout << i;
			return 0;
		}
	}

	return 0;
}
