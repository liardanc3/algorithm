#include <bits/stdc++.h>
using namespace std;

int a, b, tmp;
vector<int> A, B;
map<int, int> m;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> a >> b;
	while (a--) {
		cin >> tmp;
		m[tmp] = 1;
	}
	while (b--) {
		cin >> tmp;
		m[tmp] ? m.erase(tmp) : m[tmp] = 1;
	}
	cout << m.size();
	return 0;
}
