#include<iostream>
using namespace std;
typedef long long ll;
ll d[1010101] = {0, 1, 1};	//���� �޸��� �迭
const ll mod = 1e9 + 7;
ll fibo(int n){
	if( n <= 2)
		return 1;
	if(d[n]) return d[n];
	return d[n] = (fibo(n - 1) + fibo(n- 2)) % mod;	//���� �� ������� �ʱ� ���� ���� �޸��صд�.
}
int main(){
	int n; cin >> n;
	cout << fibo(n);
}
