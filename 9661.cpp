#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
	// 0  CY
	// 1  SK
	// 2  CY
	// 3  SK
	// 4  SK
	// 5  CY
	// 6  SK
	// 7  CY
	// 8  SK
	// 9  SK
	// 10 CY
	// 11 SK
	// 12 CY
	// 13 SK
	// 14 SK
	// 15 CY
	// 16 SK
	// ...
	// 64 SK
	// 65 
	cin >> n;
	if (n % 5 == 0 || n % 5 == 2) cout << "CY";
	else cout << "SK";
	return 0;
}