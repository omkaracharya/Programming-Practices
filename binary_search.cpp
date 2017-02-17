#include <iostream>
using namespace std;

int binary_search(int arr[], int size, int key){
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == key)
			return mid;
		if (arr[mid] > key)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int size = sizeof(arr) / sizeof(arr[0]);
	int k = 11;
	cout << ((binary_search(arr, size, k) == -1) ? "Not found" : "Found");
	cout << endl;
	return 0;
}