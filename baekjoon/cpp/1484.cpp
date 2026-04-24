#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int G;
vector<int> vect;
signed main() {
	cin >> G;

	// i = 예전, j = 현재*현재
	for (int i = 1; i <= 500000; i++) {
		int j = i * i + G;
		double sqrtj = floor(sqrt(j));
		if (sqrtj*sqrtj == j) 
			vect.push_back(sqrtj);	
	}
	
	if (vect.size()) {
		for (int i : vect)
			cout << i << '\n';
	}
	else cout << -1;
	return 0;
}