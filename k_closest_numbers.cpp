#include <iostream>
using namespace std;

int partition(int arr[], int left, int right, int key) {
	int mid = left + (right - left) / 2;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (arr[mid - 1] <= key && arr[mid + 1] > key)
			return mid;
		else if (arr[mid] < key) 
			left = mid + 1;
		else
			right = mid - 1;
	}
	return mid;
}

void k_closest_numbers(int arr[], int size, int key, int k) {
	int left = partition(arr, 0, size - 1, key);
	int right = left + 1;
	if(arr[left] == key) 
		left--;
	while(left > 0 && right < size && k > 0) {
		if(key - arr[left] < arr[right] - key) {
			cout << arr[left] << ", ";
			left--;
		} else {
			cout << arr[right] << ", ";
			right++;			
		}
		--k;
	}
	cout << endl;
}

int main(){
	int arr[] = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
	int key = 35;
	int k = 4;
	int size = sizeof(arr) / sizeof(arr[0]);
	k_closest_numbers(arr, size, key, k);
	return 0;
}