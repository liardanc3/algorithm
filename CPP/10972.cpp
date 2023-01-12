#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, tmp;
	vector<int> vect;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	if (next_permutation(vect.begin(), vect.end())) {
		for (int i : vect)
			cout << i << ' ';
	}
	else cout << -1;
	return 0;
}