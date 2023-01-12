#include <bits/stdc++.h>
using namespace std;
int N, tmp;
typedef long long ll;
vector<ll> vect;

tuple<int,int,int> tp() {
	tuple<int, int, int> ret;
	ll mn = 3000000002;
	for (int i = 0; i < vect.size()-2; i++) {
		int p = i;
		int l = i+1;
		int r = vect.size() - 1;
		
		ll sum;
		while (l < r) {
			sum = vect[i] + vect[l] + vect[r];
			if (abs(0 - sum) < mn) {
				mn = abs(0 - sum);
				ret = tuple<int, int, int>(i, l, r);
			}

			if (sum < 0)
				l++;
			else if (sum > 0)
				r--;
			else return ret;
		}
	}
	return ret;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	tuple<int, int, int> tii = tp();
	cout << vect.at(get<0>(tii)) << ' ' << vect.at(get<1>(tii)) << ' '  << vect.at(get<2>(tii));
	return 0;
}