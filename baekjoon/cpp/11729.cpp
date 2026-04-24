#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;

int N;
void move(int start, int tmp, int end, int h) {
	if (h == 1) {
		vect.push_back({ start , end });
		return;
	}

	move(start, end, tmp, h - 1);
	vect.push_back({ start, end });
	move(tmp, start, end, h - 1);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	move(1, 2, 3, N);
	cout << vect.size() << '\n';
	for (pii p : vect) {
		cout << p.first << ' ' << p.second << '\n';
	}
	return 0;
}