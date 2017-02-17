#include <iostream>
using namespace std;

int sort_array(int arr[], int left, int right, int size, int key) {
	int l = left;
	int r = right;
	while(l <= r) {
		int mid = l + (r - l) / 2;
		if(arr[mid] == key)
			return mid;
		if(mid > l && arr[mid - 1] == key)
			return mid - 1;
		if(mid < r && arr[mid + 1] == key)
			return mid + 1;
		if(arr[mid] > key)
			r = mid - 1;
		else
			l = mid + 1;
 	}
 	return -1;
}

int main(){
	int arr[] = {3, 2, 10, 4, 40};
	int size = sizeof(arr) / sizeof(arr[0]);
	int key = 4;
	int found = sort_array(arr, 0, size - 1, size, key);
	if(found != -1)
		cout << "Found at " << found;
	else
		cout << "Not found ";
	cout << endl; 
	return 0;
}