#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> pii;

int t, n, tmp;
vector<int> vect;
map<pii, int> visited;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b,a%b);
}
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		vect.clear();	
		visited.clear();
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			vect.push_back(tmp);
		}
		for (int i = 0; i < n-1; i++) {
			for (int j = i + 1; j < n; j++) {
				int a = max(vect[i], vect[j]);
				int b = min(vect[i], vect[j]);
				//if (!visited[{a, b}]) {
					sum += gcd(a, b);
					//visited[{a, b}] = 1;
				//}
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
