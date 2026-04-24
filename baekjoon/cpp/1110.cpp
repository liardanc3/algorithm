#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, cnt = 0; cin >> N;
	int origin = N;
	do {
		int sum = N / 10 + N % 10;
		N = (N % 10) * 10 + sum%10;
		cnt++;
	}while(origin != N);
	cout << cnt;
	return 0;
}