#include <bits/stdc++.h>
using namespace std;

int N, tmp, gcdmn=1e9, cnt;
vector<int> vect, gap;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
		if (i != 0)
			gap.push_back(vect[i] - vect[i - 1]);
	}
	gcdmn = gap[0];
	for (int i = 1; i < gap.size(); i++) 
		gcdmn = gcd(max(gcdmn, gap[i]), min(gcdmn, gap[i]));
	int now, next;
	for (int i = 0; i < vect.size()-1; i++) {
		now = vect[i];
		next = vect[i+1];
		while (now + gcdmn < next) {
			cnt++;
			now += gcdmn;
		}
	}
	cout << cnt;
	return 0;
}
