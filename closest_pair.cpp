#include <bits/stdc++.h>
using namespace std;

void find_closest_pair(int arr1[], int arr2[], int sum, int size1, int size2) {
	int left = 0;
	int right = size2 - 1;
	int diff = INT_MAX;
	int num1, num2;
	while(left < size1 && right >= 0) {
		if(abs(arr2[right] + arr1[left] - sum) < diff){
			diff = abs(arr2[right] + arr1[left] - sum);
			num1 = arr1[left];
			num2 = arr2[right];
		}
		if(arr2[right] + arr1[left] > sum)
			right--;
		else
			left++;
	}
	cout << num1 << " " << num2 << endl;
}

int main() {
	int arr1[] = {1,2,3,4,5};
	int arr2[] = {21,32,43,54,65};
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int sum = 33;
	find_closest_pair(arr1, arr2, sum, size1, size2);
	return 0;
}