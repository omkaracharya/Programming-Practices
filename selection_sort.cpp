#include <iostream>
using namespace std;

void selection_sort(int arr[], int size){
	for (int j = 0; j < size - 1; ++j){
		int i;
		int min_index = j;
		for (i = j; i < size; ++i) {
			if (arr[min_index] > arr[i])
				min_index = i;
		}
		swap(arr[min_index], arr[j]);
	}

	for (int i = 0; i < size; ++i){
		cout << arr[i] << " ";
	}
}

int main(){
	int arr[] = {11,2,13,4,15,6,17,8,19,10};
	int size = sizeof(arr) / sizeof(arr[0]);
	selection_sort(arr, size);
	cout << endl;
	return 0;
}