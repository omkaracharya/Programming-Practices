#include <iostream>
using namespace std;

void zig_zag_sort(int arr[], int size){
	for(int i = 0; i < size; i += 2) {
		if (i > 0 && arr[i] < arr[i - 1])
			swap(arr[i], arr[i - 1]);
		if (i < size - 1 && arr[i] < arr[i + 1])
			swap(arr[i], arr[i + 1]);
	}

	for(int i = 0; i < size; ++i) {
		cout << arr[i] << ", ";
	}
}

int main(){
	int arr[] = {1,2,3,5,6,7,8,9,10};
	int size = sizeof(arr) / sizeof(arr[0]);
	zig_zag_sort(arr, size);
	cout << endl;
	return 0;
}