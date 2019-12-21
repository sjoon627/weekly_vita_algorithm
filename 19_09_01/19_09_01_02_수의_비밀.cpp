#include <iostream>
using namespace std;
int main() {
	long long num;
	cin >> num;
	if(num == (num & (-num)))
		cout << "Yes";
	else
		cout << "No";
}

/*#include <iostream>
using namespace std;
int main() {
	long long num;
	
	cin >> num;
	
	while(num % 2 == 0)
		num /= 2;
		
	if(num == 1)
		cout << "Yes";
	else
		cout << "No";
		
}*/
