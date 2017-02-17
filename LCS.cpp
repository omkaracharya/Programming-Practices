#include <iostream>
using namespace std;

void lcs(string s1, string s2){
	int T[s1.length() + 1][s2.length() + 1];
	for(int i = 0; i <= s1.length(); ++i){
		for(int j = 0; j <= s2.length(); ++j){
			if(!i || !j)
				T[i][j] = 0;
			else if(s1[i] == s2[j])
				T[i][j] = 1 + T[i - 1][j - 1];
			else
				T[i][j] = max(T[i - 1][j], T[i][j - 1]);
		}
	}

	cout << T[s1.length()][s2.length()] << endl;
}

int main(){
	string s1, s2;
	s1 = "abcdefgh";
	s2 = "pqrabcdef";
	lcs(s1, s2);
	return 0;
}