#include <iostream>
using namespace std;

void msis(int arr[], int size){
	int T[size];

	for(int i = 0; i < size; ++i)
		T[i] = arr[i];

	for(int j = 1; j < size; ++j){
		for(int i = 0; i < j; ++i){
			if(arr[j] > arr[i] && T[j] < T[i] + arr[j])
				T[j] = T[i] + arr[j];
		}
	}

	int max = T[0];
	for(int i = 1; i < size; ++i)
		if(T[i] > max)
			max = T[i];

	cout << max << endl;

}

int main(){
	int arr[] = {1,101,3,4,100};
	int size = sizeof(arr) / sizeof(arr[0]);
	msis(arr, size);
	return 0;
}