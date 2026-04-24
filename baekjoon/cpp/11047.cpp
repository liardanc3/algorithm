#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K, tmp; cin >> N >> K;
	vector<int> vect;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	} sort(vect.rbegin(), vect.rend());
	int count = 0;
	for (int i = 0; i < vect.size(); i++) {
		if (K / vect.at(i) != 0) {
			count += K / vect.at(i);
			K -= vect.at(i) * (K / vect.at(i));
		}
	} cout << count;
	return 0;
}