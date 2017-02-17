#include <iostream>
using namespace std;

void knapsack(int W, int wts[], int rewards[], int size){
	int T[size + 1][W + 1];
	for(int i = 0; i <= size; ++i){
		for(int j = 0; j <= W; ++j){
			if(!j || !i)
				T[i][j] = 0;
			else if(wts[i - 1] <= W)
				T[i][j] = max(rewards[i - 1] + T[i - 1][j - wts[i - 1]], T[i - 1][j]);
			else
				T[i][j] = T[i - 1][j];
		}
	}

	cout << T[size][W] << endl;
}

int main(){
	int W = 50;
	int wts[] = {10, 20, 30};
	int rewards[] = {60, 100, 120};
	knapsack(W, wts, rewards, sizeof(wts)/sizeof(wts[0]));
	return 0;
}