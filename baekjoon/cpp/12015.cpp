#include <bits/stdc++.h>
using namespace std;
int N, tmp;
vector<int> vect;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> tmp;
	vect.push_back(tmp);
	for (int i = 1; i < N; i++) {
		cin >> tmp;
		if (vect.at(vect.size()-1) < tmp)
			vect.push_back(tmp);
		else {
			int idx = lower_bound(vect.begin(), vect.end(), tmp)-vect.begin();
			vect[idx] = tmp;
		}
	}
	cout << vect.size();
	return 0;
}