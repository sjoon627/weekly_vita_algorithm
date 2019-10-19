#include<iostream>
using namespace std;

int main(){
	
int arr[100], num, ans;	

	for(int i = 0; i<4; ++i){
		
		scanf("%d", &num);
		
		arr[num] = 1;
	}
	
	for(int i = 0; i<5; ++i){
		
		scanf("%d", &num);
		
		if(arr[num] == 0) ++ans;
	}
	cout << ans;
	
}
