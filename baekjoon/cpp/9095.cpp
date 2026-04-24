#include <iostream>
using namespace std;
int memo[11];
int dynamic(int tmp) {
	if (memo[tmp] != 0)
		return memo[tmp];
	else memo[tmp] = dynamic(tmp-1) + dynamic(tmp - 2) + dynamic(tmp - 3);
	return memo[tmp];
}
int main() {
	int T,tmp; cin >> T;
	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 4;  
	for (int i = 0; i < T; i++) {
		cin >> tmp;
		if (tmp <= 3) cout << memo[tmp] << "\n";
		else cout << dynamic(tmp) << "\n";
	}
	return 0;
}