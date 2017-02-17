#include <iostream>
using namespace std;

int isMultipleOfThree(int n){
	if(n == 0)
		return 1;
	if(n == 1)
		return 0;
	
	int even = 0, odd = 0;

	while(n){
		if(n & 1)
			odd++;
		n >>= 1;

		if(n & 1)
			even++;
		n >>= 1;
	}

	return isMultipleOfThree(abs(even - odd));
}

int main(){
	int n = 21;
	if(isMultipleOfThree(n))
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	return 0;
}