#include <bits/stdc++.h>
using namespace std;
double D, H, W;
int main() {
	cin >> D >> H >> W;
	double DD = D * D;
	double ans = H * H + W * W;
	cout << (int)(H * sqrt(DD / ans)) << ' ' << (int)(W * sqrt(DD / ans));
	return 0;
}