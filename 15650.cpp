#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M, check; cin >> N >> M;
	vector<int> vect;
	for (int i = 1; i <= N; i++) {
		vect.clear();
		vect.push_back(i);
		check = 1;
		for (int j = 1; j < M; j++) {
			for (int k = 1; k < N; k++) {
				vect.push_back(i + k);
			}
		}
	}
	return 0;
}