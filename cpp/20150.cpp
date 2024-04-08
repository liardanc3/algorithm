#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int> tii;
int N;
vector<tii> vect;
int ccw(pii A, pii B, pii C) {
	int Ax = A.first, Ay = A.second;
	int Bx = B.first, By = B.second;
	int Cx = C.first, Cy = C.second;

	int dx1 = Bx - Ax;
	int dy1 = By - Ay;
	int dx2 = Cx - Ax;
	int dy2 = Cy - Ay;

	if (1LL * dx1 * dy2 > 1LL * dx2 * dy1) return 1;
	if (1LL * dx1 * dy2 < 1LL * dx2 * dy1) return -1;
	if (dx1 == 0 && dy1 == 0) return 0;
	if (1LL * dx1 * dx2 < 0 || 1LL * dy1 * dy2 < 0) return -1;
	if (1LL * dx1 * dx1 + 1LL * dy1 * dy1 < 1LL * dx2 * dx2 + 1LL * dy2 * dy2) return 1;
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int x1, y1, x2, y2;
	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		vect.push_back({ x1,x2,y1,y2 });
	}
	sort(vect.begin(), vect.end());

	for (int i = 0; i < N-1; i++) {
		int end = get<1>(vect[i]);
		for (int j = i + 1; j < N; j++) {
			if (get<0>(vect[j]) <= end) {
				int Ax = get<0>(vect[i]), Ay = get<2>(vect[i]);
				int Bx = get<1>(vect[i]), By = get<3>(vect[i]);
				int Cx = get<0>(vect[j]), Cy = get<2>(vect[j]);
				int Dx = get<1>(vect[j]), Dy = get<3>(vect[j]);
				int t1 = ccw({ Ax,Ay }, { Bx,By }, { Cx,Cy }) * ccw({ Ax,Ay }, { Bx,By }, { Dx,Dy });
				if (t1 > 0) continue;
				int t2 = ccw({ Cx,Cy }, { Dx,Dy }, { Ax,Ay }) * ccw({ Cx,Cy }, { Dx,Dy }, { Bx,By });

				if (t2 <= 0) {
					cout << 1;
					return 0;
				}
			}
			else break;
		}
	}
	cout << 0;
	return 0;
}