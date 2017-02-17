#include <iostream>
using namespace std;

void lis(int arr[], int size){
	if(!size){
		cout << "Nothing" << endl;
		return;
	}
	int T[size];
	for(int i = 0; i < size; ++i)
		T[i] = 0;
	T[0] = 1;

	for(int i = 1; i < size; ++i){
		for(int j = 0; j < i; ++j){
			if(arr[i] > arr[j] && T[j] + 1 > T[i])
				T[i] = T[j] + 1;
		}
	}

	int max = T[0];
	for(int i = 1; i < size; ++i){
		if(max < T[i])
			max = T[i];
	}

	cout << max << endl;
}

int main(){
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
	int size = sizeof(arr) / sizeof(arr[0]);
	lis(arr, size);
	return 0;
}