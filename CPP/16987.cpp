#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;

int n, a, b;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> a >> b;
		vect.push_back({ a,b });
	}

	return 0;
}