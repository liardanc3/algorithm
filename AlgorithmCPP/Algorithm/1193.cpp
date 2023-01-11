#include <bits/stdc++.h>
using namespace std;
int main() {
	int X; cin >> X;
	if (X == 1)
		cout << "1/1";
	else if (X == 2)
		cout << "1/2";
	else {
		int up = 1, dn = 2;
		int bup = 1, bdn = 1;
		for (int i = 3; i <= X; i++) {
			if (up == 1){
				if (bup == up) {
					bup = up, bdn = dn;
					up++, dn--;
				}
				else if (bup - 1 == up && bdn + 1 == dn) {
					bup = up, bdn = dn;
					dn++;
				}
			}
			else if (dn == 1) {
				if (bdn == dn) {
					bup = up, bdn = dn;
					up--, dn++;
				}
				else if (bup + 1 == up && bdn - 1 == dn) {
					bup = up, bdn = dn;
					up++;
				}
			}
			else {
				if (bdn < dn) {
					bup = up, bdn = dn;
					up--, dn++;
				}
				else {
					bup = up, bdn = dn;
					up++, dn--;
				}
			}
		}
		cout << up << "/" << dn;
	}
	return 0;
}