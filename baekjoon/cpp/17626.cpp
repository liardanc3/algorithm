#include <iostream>
#include <math.h>
using namespace std;

int min(int a, int b) {
	if (a < b) return a;
	else return b;
	return -1;
}

int main() {
	int num;
	cin >> num;
	int *memo = new int[num+1];
	for (int i = 0; i <= num; i++) {
		memo[i] = 5;
	}
	for (int i = 1; i <= num; i++) {
		if ((int)sqrt(i) * (int)sqrt(i) == i)
			memo[i] = 1;
	}
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j*j<i; j++) {
			memo[i] = min(memo[i], memo[j * j] + memo[i - j * j]);
			//memo[804] = min(memo[804], memo[4]+memo[800])
		}
	}
	cout << memo[num];

	return 0;
}