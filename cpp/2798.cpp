#include <bits/stdc++.h>
using namespace std;
int n, m, tmp, dp[101][101][101]{ 0, };
vector<int> vect;
int makedp() {
	for (int i = 1; i < vect.size(); i++) {
		for (int j = i+1; j < vect.size(); j++) {
			for (int k = j+1; k < vect.size(); k++) {
				dp[i][j][k] = vect[i] + vect[j] + vect[k];
				if (dp[i][j][k] > m)
					dp[i][j][k] = 0;
			}
		}
	}
	return *max_element(&dp[0][0][0], &dp[100][100][101]);
}
int main() {
	vect.push_back(0);
	cin >> n >> m;
	while (n--) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	cout << makedp();

	return 0;
}