#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
	int left_size = mid - left + 1;
	int right_size = right - mid;
	int L[left_size], R[right_size];
	for (int i = 0; i < left_size; ++i)
		L[i] = arr[left + i];
	for (int i = 0; i < right_size; ++i)
		R[i] = arr[mid + i + 1];

	int i = 0, j = 0, k = left;
	while (i < left_size && j < right_size) {
		if (L[i] < R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < left_size) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < right_size) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(int arr[], int left, int right){
	if(left < right) {
		int mid = left + (right - left) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main(){
	int arr[] = {11,2,13,4,15,6,17,8,19,10};
	int size = sizeof(arr) / sizeof(arr[0]);
	merge_sort(arr, 0, size - 1);
	for (int i = 0; i < size; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}