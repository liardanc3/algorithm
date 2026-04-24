#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	ll dx1 = 0LL + x2 - x1;
	ll dy1 = 0LL + y2 - y1;
	ll dx2 = 0LL + x3 - x1;
	ll dy2 = 0LL + y3 - y1;

	if (dx1 * dy2 > dy1 * dx2) return 1;
	if (dx1 * dy2 < dy1 * dx2) return -1;
	if (dx1 == 0 && dy1 == 0) return 0;
	if (dx1 * dx2 < 0 || dy1 * dy2 < 0) return -1;
	if (dx1 * dx1 + dy1 * dy1 < dx2 * dx2 + dy2 * dy2) return 1;
	return 0;
}
int main() {
	double x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	vector<pii> vect;
	vect.push_back({ x1,y1 });
	vect.push_back({ x2,y2 });
	sort(vect.begin(), vect.end());
	x1 = vect[0].first;
	y1 = vect[0].second;
	x2 = vect[1].first;
	y2 = vect[1].second;
	vector<pii> vect1;
	vect1.push_back({ x3,y3 });
	vect1.push_back({ x4,y4 });
	sort(vect1.begin(), vect1.end());
	x3 = vect1[0].first;
	y3 = vect1[0].second;
	x4 = vect1[1].first;
	y4 = vect1[1].second;
	vector<tuple<double,double,double,double>> vect2;
	vect2.push_back({ x1,y1,x2,y2 });
	vect2.push_back({ x3,y3,x4,y4 });
	sort(vect2.begin(), vect2.end());
	x1 = get<0>(vect2[0]);
	y1 = get<1>(vect2[0]);
	x2 = get<2>(vect2[0]);
	y2 = get<3>(vect2[0]);
	x3 = get<0>(vect2[1]);
	y3 = get<1>(vect2[1]);
	x4 = get<2>(vect2[1]);
	y4 = get<3>(vect2[1]);

	int t1 = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
	int t2 = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);
	if (t1 <= 0 && t2 <= 0) {
		cout << 1;
		// 일직선 없음
		if (x2 - x1 != 0 && x4 - x3 != 0) {
			double Agradient = (y2 - y1) / (x2 - x1);
			double Bgradient = (y4 - y3) / (x4 - x3);
			if (Agradient == Bgradient) {
				if (x3 < x2) return 0;
				printf("\n%.16f %.16f", x2, y2);
				return 0;
			}
			double Ay0 = y1 - (Agradient * x1);
			double By0 = y3 - (Bgradient * x3);
			double ans_x = (By0 - Ay0) / (Agradient - Bgradient);
			double ans_y = (Agradient * ans_x) + Ay0;
			printf("\n%.16f %.16f", ans_x, ans_y);
		}
		// A가 일직선
		else if (x2-x1==0 && x4-x3!=0){
			double Bgradient = (y4 - y3) / (x4 - x3);
			double By0 = y3 - (Bgradient * x3);
			double ans_x = x2;
			double ans_y = Bgradient * ans_x + By0;
			printf("\n%.16f %.16f", ans_x, ans_y);
		}
		// B가 일직선
		else if (x4 - x3 == 0 && x2-x1!=0) {
			double Agradient = (y2 - y1) / (x2 - x1);
			double Ay0 = y1 - (Agradient * x1);
			double ans_x = x3;
			double ans_y = Agradient * ans_x + Ay0;
			printf("\n%.16f %.16f", ans_x, ans_y);
		}
		// 둘다 일직선
		else {
			if (y3 < y2) return 0;
			printf("\n%.16f %.16f", x2, y2);
		}
	}
	else cout << 0;
	return 0;
}