#include <bits/stdc++.h>
using namespace std;
int S, N, tmp, l, r, sum, res;
vector<int> vect;

void two_pointer() {
	sum = vect.at(0); res = 100001;
	l = 0; r = 0;
	while (r < N && l<=r) {
		if (sum >= S) {
			res = min(res, r - l + 1);
			sum -= vect.at(l);
			l++;
		}
		else if (sum < S) {
			r++;
			if (r >= N) break;
			sum += vect.at(r);
		}
	}
	if (res==100001)
		cout << 0;
	else cout << res;
}


int main() {
	cin >> N >> S;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	two_pointer();

	return 0;
}