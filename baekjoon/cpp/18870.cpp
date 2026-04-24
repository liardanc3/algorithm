#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int N, tmp;
	cin >> N;
	vector<int> vect;
	vector<int> uniq;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	uniq = vect;
	sort(uniq.begin(), uniq.end());
	uniq.erase(unique(uniq.begin(), uniq.end()),uniq.end());
	for (int i = 0; i < vect.size(); i++) {
		cout << lower_bound(uniq.begin(), uniq.end(), vect.at(i)) - uniq.begin() << " ";
	}
	return 0;
}