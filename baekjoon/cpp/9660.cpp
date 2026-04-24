#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main() {
	cin >> n;
	// 0  CY
	// 1  SK
	// 2  CY
	// 3  SK
	// 4  SK
	// 5  SK
	// 6  SK
	// 7  CY
	// 8  SK
	// 9  CY
	// 10 SK
	// 11 SK
	// 12 SK
	// 13 SK
	// 14 CY
	if (n % 7 == 0 || n% 7== 2) cout << "CY";
	else cout << "SK";
	return 0;
}