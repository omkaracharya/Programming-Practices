#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        if(!n){
            cout << 0 << endl;
            continue;
        }
        long long T[n + 1];
        T[0] = 1;
        T[1] = 1;
        long long sum = 0;
        int i = 2, count = 0;
        while(1){
            T[i] = T[i - 1] + T[i - 2];
            if(T[i] > n)
                break;
            if(!(T[i] & 1)){
                sum += T[i];       
            }
            ++i;
        }
        for(int j = 0; j < i; ++j)
            cerr << T[j] << ' ';
        cerr << endl;
        cout << sum << endl;
    }
    return 0;
}
