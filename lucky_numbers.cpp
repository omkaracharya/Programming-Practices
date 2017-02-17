#include <iostream>
using namespace std;

int isLucky(int n){
	static int counter = 2;

	if(counter > n)
		return 1;

	if(n % counter == 0)
		return 0;

	n -= n/counter;
	counter++;
	return isLucky(n);
}

int main(){
	int n = 22;
	if(isLucky(n))
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	return 0;
}