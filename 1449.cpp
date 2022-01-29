#include <bits/stdc++.h>
using namespace std;
int N, L, x, tmp;
vector<int> vect;
int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	int ret = 0;
	int ans = 1;
	for (int i = 0; i < vect.size() - 1; i++) {
		if (vect[i + 1] - vect[i] + ans <= L)
			ans += vect[i + 1] - vect[i];
		else {
			ret++;
			ans = 1;
			vect.erase(vect.begin(), vect.begin()+i+1);
			i = -1;
		}
	}
	cout << ret + 1;
	return 0;
}