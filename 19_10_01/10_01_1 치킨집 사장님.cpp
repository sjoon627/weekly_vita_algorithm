#include<iostream>
using namespace std;
typedef long long ll;
ll d[1010101] = {0, 1, 1};	//답을 메모할 배열
const ll mod = 1e9 + 7;
ll fibo(int n){
	if( n <= 2)
		return 1;
	if(d[n]) return d[n];
	return d[n] = (fibo(n - 1) + fibo(n- 2)) % mod;	//여러 번 계산하지 않기 위해 답을 메모해둔다.
}
int main(){
	int n; cin >> n;
	cout << fibo(n);
}
