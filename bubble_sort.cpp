#include <iostream>
using namespace std;

void bubble_sort(int arr[], int size){
	bool swapped = false;
	for (int j = 0; j < size - 1; ++j) {
		swapped = false;
		for (int i = 0; i < size - j - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
	}

	for (int i = 0; i < size; ++i){
		cout << arr[i] << " ";
	}
}

int main(){
	int arr[] = {11,2,13,4,15,6,17,8,19,10};
	int size = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, size);
	cout << endl;
	return 0;
}