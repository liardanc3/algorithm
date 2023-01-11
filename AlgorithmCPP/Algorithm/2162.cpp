#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<pii> vect;
int tree[3001];
int getRoot(int i) {
	return i == tree[i] ? i : tree[i] = getRoot(tree[i]);
}
ll ccw(pii A, pii B, pii C) {
	ll Ax = A.first, Ay = A.second;
	ll Bx = B.first, By = B.second;
	ll Cx = C.first, Cy = C.second;

	ll dx1 = Bx - Ax;
	ll dy1 = By - Ay;
	ll dx2 = Cx - Ax;
	ll dy2 = Cy - Ay;

	if (dx1 * dy2 > dx2 * dy1) return 1;
	if (dx1 * dy2 < dx2 * dy1) return -1;
	if (dx1 == 0 && dy1 == 0) return 0;
	if (dx1 * dx2 < 0 || dy1 * dy2 < 0) return -1;
	if (dx1 * dx1 + dy1 * dy1 < dx2 * dx2 + dy2 * dy2) return 1;
	return 0;
}
void init() {
	for (int i = 0; i <= 3000; i++)
		tree[i] = i;
}
int main() {
	int N, x1, y1, x2, y2;
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		vect.push_back({ x1,y1 });
		vect.push_back({ x2,y2 });
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			ll t1 = ccw(vect[2 * i], vect[2 * i + 1], vect[2 * j]) * ccw(vect[2 * i], vect[2 * i + 1], vect[2 * j + 1]);
			ll t2 = ccw(vect[2 * j], vect[2 * j + 1], vect[2 * i]) * ccw(vect[2 * j], vect[2 * j + 1], vect[2 * i + 1]);
			if (t1 <= 0 && t2 <= 0) {
				tree[getRoot(j)] = getRoot(i);
			}
		}
	}
	int group[3001]{ 0, };
	for (int i = N-1; i >=0; i--) {
		tree[getRoot(i)] = getRoot(i);
		group[tree[i]]++;
	}
	int group_count = 0, mx = 0;
	for (int i = 0; i < vect.size() / 2; i++) {
		if (tree[i] == i) group_count++;
		mx = max(mx, group[i]);
	}
	cout << group_count << '\n';
	cout << mx;

	return 0;
}