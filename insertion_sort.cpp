#include <iostream>
using namespace std;

void insertion_sort(int arr[], int size){
	for (int j = 1; j < size; ++j) {
		int i = j - 1;
		int key = arr[j];
		while (i > -1 && arr[i] > key) {
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = key;
	}

	for (int i = 0; i < size; ++i){
		cout << arr[i] << " ";
	}
}

int main(){
	int arr[] = {11,2,13,4,15,6,17,8,19,10};
	int size = sizeof(arr) / sizeof(arr[0]);
	insertion_sort(arr, size);
	cout << endl;
	return 0;
}