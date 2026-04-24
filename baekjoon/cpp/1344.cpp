#include <bits/stdc++.h>
using namespace std;

double rate, a, b, C[19][20];
vector<int> vect{ 0,1,4,6,8,9,10,12,14,15,16,18 };
void makeC(int now) {
	if (now == 19)
		return;
	C[now][0] = 1, C[now][now] = 1;
	for (int i = 1; i < now; i++)
		C[now][i] = C[now - 1][i - 1] + C[now - 1][i];
	makeC(now + 1);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	C[0][0] = 1;
	makeC(1);
	cin >> a >> b;
	for (int i = 0; i < 12; i++) {
		int p1 = vect[i];
		double a1 = C[18][p1] * pow(a / 100, p1)* pow((100 - a) / 100, abs(18 - p1));
		for (int j = 0; j < 12; j++) {
			int p2 = vect[j];
			double a2 = C[18][p2] * pow(b / 100, p2) * pow((100 - b) / 100, abs(18 - p2));
			rate += a1 * a2;
		}
	}
	cout << fixed << setprecision(15);
	cout << 1 - rate;
	return 0;
}