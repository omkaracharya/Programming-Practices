#include <iostream>
using namespace std;

void lps(string s){
	if(s.length() == 0 || s.length() == 1){
		cout << s.length() << endl;
		return;
	}

	int len = s.length();
	int T[len][len];

	int first, last, sbstr;

	for(sbstr = 1; sbstr <= len; sbstr++){
		for(first = 0; first < len - sbstr + 1; first++){
			last = first + sbstr - 1;
			if(sbstr == 1)
				T[first][last] = 1;
			else if(s[first] == s[last] && sbstr == 2)
				T[first][last] = 2;
			else if(s[first] == s[last])
				T[first][last] = 2 + T[first + 1][last - 1];
			else
				T[first][last] = max(T[first][last - 1], T[first + 1][last]);
		}
	}

	// for(first = 0; first < len; ++first){
	// 	for(last = 0; last < len; ++last){
	// 		cout << T[first][last] << ' ';
	// 	}
	// 	cout << endl;
	// }

	// cout << endl;
	cout << T[0][len - 1] << endl;
}

int main(){
	string s = "geeks for geeks";
	lps(s);
	return 0;
}