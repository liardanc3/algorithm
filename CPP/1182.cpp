#include <bits/stdc++.h>
using namespace std;
int N, S, tmp, cnt = 0;
vector<int> vect;
int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	for (int i = 1; i < (1 << N); i++) {
		int sum = 0;
		for (int k = 0; k < N; k++) {
			if (i & (1 << k))
				sum += vect[k];
		}
		if (sum == S)
			cnt++;
	}
	cout << cnt;
	return 0;
}