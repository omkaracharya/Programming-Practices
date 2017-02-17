#include <iostream>
using namespace std;

int partition(int arr[], int left, int right) {
	int i = left - 1;
	int j = left;
	while(j < right) {
		if(arr[j] < arr[right]){
			++i;
			swap(arr[j], arr[i]);
		}
		++j;
	}
	swap(arr[++i], arr[right]);
	return i;
}

void selection(int arr[], int left, int right, int size, int k){
	int q = partition(arr, left, right);
	if(q == k)
		return;
	if(q < k)
		selection(arr, q + 1, right, size, k);
	else
		selection(arr, left, q - 1, size, k);
}

int main(){
	int arr[] = {11,2,33,14,5,6,74,48,95,170};
	int size = sizeof(arr) / sizeof(arr[0]);
	int k = 1;
	selection(arr, 0, size - 1, size, k);
	cout << arr[k] << endl;
	return 0;
}