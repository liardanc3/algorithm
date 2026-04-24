#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> vect;
	for (int i = 1; i <= N; i++)
		vect.push_back(i);
	do {
		for (int j : vect)
			cout << j << ' ';
		cout << '\n';
	} while (next_permutation(vect.begin(), vect.end()));
	return 0;
}