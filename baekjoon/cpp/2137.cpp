#include <bits/stdc++.h>
using namespace std;

int gcd (int a, int b) {
	return a % b == 0 ? b : gcd(b, a % b);
}

int main() {
	double a, b;
	cin >> a >> b;
	double n = a / b;
	double gap = 10;
	int ans_a, ans_b;
	for (int i = 32767; i >=2; i--) {
		if (i == b) continue;
		double aa = a * (double)i / b;
		int tmp = aa / 1;	
		
		double g = abs(n - ((double)tmp / (double)i));
		double gg = abs(n - ((double)(tmp + 1) / (double)i));
		double ggg = abs(n - ((double)(tmp - 1) / (double)i));

		if (tmp < i && 0 < tmp&&gap > g && gcd(i, tmp)==1 ) {
			ans_a = tmp;
			ans_b = i;
			gap = g;
		}
		if (tmp + 1 < i && 0 < tmp + 1&&gap > gg && gcd(i, tmp+1) == 1 ){
			ans_a = tmp+1;
			ans_b = i;
			gap = gg;
		}
		if (tmp - 1 >= 1 && tmp - 1 < i && gap > gg && gcd(i, tmp-1) == 1 ) {
			ans_a = tmp - 1;
			ans_b = i;
			gap = ggg;
		}
	}
	cout << ans_a << ' ' << ans_b;
	
	return 0;
}