#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N;
double x_center, y_center;
vector<pii> vect;

double circle() {
	double ans = 0;
	for (int i = 0; i < N; i++) {
		double x = vect.at(i).first + vect.at(i+1).first;
		double y = vect.at(i).second - vect.at(i+1).second;
		
		ans += (x*y);
	}
	return abs(ans/2);
}
int main() {
	cin >> N;
	double x, y, x_sum=0, y_sum=0;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		x_sum += x; y_sum += y;
		vect.push_back(pii(x, y));
	}
	vect.push_back(vect.at(0));
	x_center = x_sum / N;
	y_center = y_sum / N;
	double ANS = circle();
	printf("%.1f", ANS);

	return 0;
}