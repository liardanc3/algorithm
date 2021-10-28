#include <bits/stdc++.h>
using namespace std;
int N, S, cnt;
typedef long long ll;
ll tmp;
vector<ll> vect;
vector<int> m1, m2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	m1.push_back(0); m2.push_back(0);
	cnt = 0;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	//sort(vect.begin(), vect.end());
	int halfL = N / 2, halfR = N - halfL;
	for (int i = 1; i < pow(2, halfL); i++) {
		int sum = 0, count = 0;
		bitset<20> bit(i);
		for (int k = 0; count < bit.count(); k++) {
			if (bit[k] == 1) {
				count++;
				sum += vect[k];
			}
		}
		m1.push_back(sum);
	} sort(m1.begin(), m1.end());
	for (int i = 1; i < pow(2, halfR); i++) {
		int sum = 0, count = 0;
		bitset<20> bit(i);
		for (int k = 0; count < bit.count(); k++) {
			if (bit[k] == 1) {
				count++;
				sum += vect[k+halfL];
			}
		}
		m2.push_back(sum);
	} sort(m2.begin(), m2.end());

	ll ans = 0;
	int left = 0, right = m2.size() - 1;
	while (left < m1.size() && right >= 0) {
		if (m1[left] + m2[right] == S) {
			ll L = 1, R = 1;

			while (left + 1 < m1.size() && m1[left] == m1[left + 1]) {
				left++;
				L++;
			} left++;
			while (right - 1 >= 0 && m2[right] == m2[right - 1]) {
				right--;
				R++;
			} right--;

			ans += (L * R);
		}
		else if (m1[left] + m2[right] < S)
			left++;
		else right--;
	}
	if (S == 0) ans--;
	cout << ans;
	return 0;
}