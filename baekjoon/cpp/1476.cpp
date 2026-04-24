#include <bits/stdc++.h>
using namespace std;
int main() {
	int modE = 15, modS = 28, modM = 19;
	int e, s, m;
	cin >> e >> s >> m;
	int N_1 = modE * modS * modM / modE;
	int M_1;
	for (int i = 1;; i++) {
		if ((N_1 * i) % modE == 1) {
			M_1 = i;
			break;
		}
	}
	int N_2 = modE * modS * modM / modS;
	int M_2;
	for (int i = 1;; i++) {
		if ((N_2 * i) % modS == 1) {
			M_2 = i;
			break;
		}
	}
	int N_3 = modE * modS * modM / modM;
	int M_3;
	for (int i = 1;; i++) {
		if ((N_3 * i) % modM == 1) {
			M_3 = i;
			break;
		}
	}
	if (e % modE == 0 && s % modS == 0 && m % modM == 0)
		cout << modE * modS * modM;
	else cout << (M_1 * e * N_1 + M_2 * s * N_2 + M_3 * m * N_3) % (N_1 * modE);
	return 0;
}