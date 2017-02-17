#include <iostream>
using namespace std;

void permute(string s, int left, int right){
	if(left == right){
		cout << s << endl;
	}else{
		for(int i = left; i <= right; ++i){
			swap(s[left], s[i]);
			permute(s, left + 1, right);
			swap(s[left], s[i]);
		}
	}
}

int main(){
	string s = "abc";
	permute(s, 0, s.length() - 1);
	return 0;
}