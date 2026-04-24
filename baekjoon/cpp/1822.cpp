#include <bits/stdc++.h>
using namespace std;

int A, B, tmp;
set<int> s;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> A >> B;
	while (A--) {
		cin >> tmp;
		s.insert(tmp);
	}
	while (B--) {
		cin >> tmp;
		if (s.find(tmp) != s.end())
			s.erase(tmp);
	}
	cout << s.size() << '\n';
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << ' ';
	}

	return 0;
}