#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
int main(){
	int n; cin >> n;
	vector<pair<int, int>> seq(n);
	for(int i = 0; i<n; ++i)
		cin >> seq[i].second >> seq[i].first;
	
	sort(seq.begin(), seq.end());	//이터레이터를 사용하여 정렬
	int e = 0, ans = 0;
	for(int i = 0; i<n; ++i){
		if(seq[i].second >= e){		//i번째 부업이 마지막 부업이 끝난 시간보다 크거나 같다면
			++ans;		//정답을 1 증가시키고
			e = seq[i].first;	//부업이 끝난 시간을 갱신
		}
	}
	printf("%d", ans);
}
