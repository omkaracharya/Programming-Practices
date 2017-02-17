#include <bits/stdc++.h>
using namespace std;

void counting_sort(int arr[], int size){
	int max_element = INT_MIN;
	for (int i = 0; i < size; ++i) {
		if (max_element < arr[i]) {
			max_element = arr[i];
		}
	}

	int counts[max_element + 1];
	for (int i = 0; i < max_element + 1; ++i)
		counts[i] = 0;

	for (int i = 0; i < size; ++i)
		counts[arr[i]]++;

	for (int i = 1; i < max_element + 1; ++i)
		counts[i] += counts[i - 1];

	int arr2[size];

	for (int i = size - 1; i >= 0; --i){
		arr2[counts[arr[i]] - 1] = arr[i];
		counts[arr[i]]--; 
	}

	for (int i = 0; i < size; ++i)
		arr[i] = arr2[i];

	for (int i = 0; i < size; ++i){
		cout << arr[i] << " ";
	}
}

int main(){
	int arr[] = {11,2,13,4,15,6,17,8,19,10};
	int size = sizeof(arr) / sizeof(arr[0]);
	counting_sort(arr, size);
	cout << endl;
	return 0;
}