#include <bits/stdc++.h>
using namespace std;

int N, tmp, sum;
vector<int> vect;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	for (int i = vect.size() - 2; i >= 0; i--) {
		if (vect[i] >= vect[i + 1]) {
			sum += (vect[i] - (vect[i + 1] - 1));
			vect[i] = vect[i + 1] - 1;
		}
	}
	cout << sum;
	return 0;
}
