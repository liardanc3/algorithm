#include <bits/stdc++.h>
using namespace std;
int main() {
	int cnt = 0; char now;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> now;
			if (now == '.') continue;
			if ((i + j) % 2 == 0)cnt++;
		}
	}
	cout << cnt;
	return 0;
}