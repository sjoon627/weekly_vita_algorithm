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
	
	sort(seq.begin(), seq.end());	//���ͷ����͸� ����Ͽ� ����
	int e = 0, ans = 0;
	for(int i = 0; i<n; ++i){
		if(seq[i].second >= e){		//i��° �ξ��� ������ �ξ��� ���� �ð����� ũ�ų� ���ٸ�
			++ans;		//������ 1 ������Ű��
			e = seq[i].first;	//�ξ��� ���� �ð��� ����
		}
	}
	printf("%d", ans);
}
