#include<iostream>

using namespace std;
typedef long long ll;

ll pos[2][1010];
ll dist(int i, int j){
	return (pos[0][i] - pos[0][j]) * (pos[0][i] - pos[0][j])
		+ (pos[1][i] - pos[1][j]) * (pos[1][i] - pos[1][j]);
}

int main(){
	int n; cin >> n;
	
	for(int i = 0; i<n; ++i)
		cin >> pos[0][i] >> pos[1][i];
	
	int ans1 = 0, ans2 = 0;
	ll maxDist = 0;
	
	for(int i = 0; i<n; ++i){
		
		for(int j = i + 1; j<n; ++j){
			
			ll d = dist(i, j);
			
			if(maxDist < d){
				maxDist = d;
				ans1 = i;
				ans2 = j;
			}
			
		}
		
	}
	
	cout << ans1 + 1 << ' ' << ans2 + 1;
}
