#include <iostream>
using namespace std;

void func(vector <int> &v, string a, string b, string c, int n){
	if(n >= v.size()){

	}

	for(int i = 0; i < 10; ++i){

	}

	func(v, a, b, c, n + 1);
}

int main(){
	string a, b, c;
	while(cin >> a >> b >> c){
		std::vector<int> v;
		for(int i = 0; i < a.length(); ++i)
			if(a[i] == '?')
				v.push_back(i);
		for(int i = 0; i < b.length(); ++i)
			if(b[i] == '?')
				v.push_back(a.length() + i);
		for(int i = 0; i < c.length(); ++i)
			if(c[i] == '?')
				v.push_back(b.length() + i);

		// if(v.empty()){
		// 	int an = atoi(a.c_str());
		// 	int bn = atoi(b.c_str());
		// 	int cn = atoi(c.c_str());
		// 	if(an * bn == cn){
		// 		cout << a << ' ' << b << ' ' << c << endl;
		// 		continue;
		// 	} else {
		// 		cout << "inconsistent" << endl;
		// 		continue;
		// 	}
		// }

		func(v, a, b, c, 0);
		
	}
	return 0;
}