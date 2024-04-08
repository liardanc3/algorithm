#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int left, right;
	cin >> left >> right;
	vector<int> a(right+1);
	fill(a.begin(), a.end(), 1);
	a.at(1) = 0;
	for (int i = 2; i <= right; i++) {
		for (int j = 1; j*j <= i; j++) {
			if (a.at(j) == 1) {
				if (i % j == 0) {
					a.at(i) = 0; break;
				}
			}
		}
	}
	for (int j = left; j <= right; j++) {
		if (a.at(j) == 1) cout << j << "\n";
	}
	return 0;
}


