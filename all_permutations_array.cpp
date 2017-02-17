#include <iostream>
#include <vector>
using namespace std;

void print_array(vector <int> &v){
	for(auto x: v)
		cout << x;
	cout << endl;
}

void permute(vector <int> &v, int left, int right){
	if(left == right){
		print_array(v);
	}else{
		for(int i = left; i <= right; ++i){
			swap(v[left], v[i]);
			permute(v, left + 1, right);
			swap(v[left], v[i]);
		}
	}
}

int main(){
	vector <int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	permute(v, 0, v.size() - 1);
	return 0;
}