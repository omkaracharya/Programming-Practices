#include <iostream>
using namespace std;

int partition(int arr[], int left, int right) {
	int i = left - 1;
	int j = left;
	while (j < right) {
		if (arr[j] < arr[right]) {
			++i;
			swap(arr[i], arr[j]);
		}
		++j;
	}
	swap(arr[i + 1], arr[j]);
	return i + 1;
}

void quick_sort(int arr[], int left, int right){
	if(left < right) {
		int pivot = partition(arr, left, right);
		quick_sort(arr, left, pivot - 1);
		quick_sort(arr, pivot + 1, right);
	}
}

int main(){
	int arr[] = {11,2,13,4,15,6,17,8,19,10};
	int size = sizeof(arr) / sizeof(arr[0]);
	quick_sort(arr, 0, size - 1);
	for (int i = 0; i < size; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}