#include <bits/stdc++.h>
using namespace std;
string a, b;

int main() {
	cin >> a >> b;
	if (a.size() > b.size())
		swap(a, b);
	return 0;
}