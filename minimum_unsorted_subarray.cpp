#include <iostream>
using namespace std;

void minimum_unsorted_subarray(int arr[], int size){
	int left = 0, right = size - 1;
	while(left < size && arr[left] < arr[left + 1])
		left++;

	while(right >= 0 && arr[right] > arr[right - 1])
		right--;

	// cout << left << " " << right << " " << arr[left] << " " << arr[right] << endl;

	int min, max;
	min = arr[left];
	max = arr[left];

	for(int i = left + 1; i <= right; ++i) {
		if (max < arr[i]) {
			max = arr[i];
		}

		if (min > arr[i]) {
			min = arr[i];
		}
	}

	for(int i = 0; i < left; ++i) {
		if (arr[i] > min) {
			left = i;
			break;
		}
	}

	for(int i = right + 1; i < size; ++i) {
		if (arr[i] < max) {
			right = i;
			break;
		}
	}

	cout << left << " " << right << " " << arr[left] << " " << arr[right] << endl;


}

int main(){ 
	// int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	int arr[] = {0, 1, 15, 25, 6, 7, 30, 40, 50};
	int size = sizeof(arr) / sizeof(arr[0]);
	minimum_unsorted_subarray(arr, size);
	return 0;
}