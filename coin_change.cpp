#include <iostream>
using namespace std;

void knapsack(int total, int coins[], int size){
	int T[size][total + 1];

	for(int i = 0; i < size; ++i)
		T[i][0] = 1;

	for(int i = 0; i < size; ++i){
		for(int j = 1; j <= total; ++j){
			int take = (j - coins[i] >= 0) ? T[i][j - coins[i]]: 0;
			int donttake = (i > 0) ? T[i - 1][j] : 0;
			T[i][j] = take + donttake;
		}
	}

	cout << T[size - 1][total] << endl;
}

int main(){
	int total = 4;
	int coins[] = {1, 2, 3};
	knapsack(total, coins, sizeof(coins)/sizeof(coins[0]));
	return 0;
}