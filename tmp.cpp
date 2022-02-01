#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define PI 3.141592
#define PARAM 20037508.34

using namespace std;

double lon, lat, x, y;

signed main() {
	cin >> lon >> lat;
	lon = 126.6328428, lat = 37.378413;
	x = (lon * PARAM) / 180;
	y = log(tan(((90 + lat) * PI) / 360)) / (PI / 180);
	y = (y * PARAM) / 180;
	cout << x << ' ' << y;
	return 0;
}