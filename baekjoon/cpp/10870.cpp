#include <bits/stdc++.h>
using namespace std;
int N, F[21]{ 0, };

int main() {
	cin >> N;
	F[1] = 1;
	for (int i = 2; i <= N; i++) {
		F[i] = F[i - 1] + F[i - 2];
	}
	cout << F[N];
	return 0;
}