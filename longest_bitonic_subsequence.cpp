#include <iostream>
using namespace std;

void lbs(int arr[], int size){
	int lis[size], lds[size];

	for(int i = 0; i < size; ++i)
		lis[i] = lds[i] = 1;

	//LIS

	for(int j = 1; j < size; ++j){
		for(int i = 0; i < j; ++i){
			if(arr[j] > arr[i] && 1 + lis[i] > lis[j])
				lis[j] = 1 + lis[i];
		}
	}

	//LDS

	for(int j = size - 2; j >= 0; --j){
		for(int i = size - 1; i > j; --i){
			if(arr[j] > arr[i] && 1 + lis[i] > lis[j])
				lis[j] = 1 + lis[i];
		}
	}

	int max = lds[0] + lis[0] - 1;
	for(int i = 1; i < size; ++i)
		if(lds[i] + lis[i] - 1 > max)
			max = lds[i] + lis[i] - 1;

	cout << max << endl;
}

int main(){
	int arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
	int size = sizeof(arr) / sizeof(arr[0]);
	lbs(arr, size);
	return 0;
}