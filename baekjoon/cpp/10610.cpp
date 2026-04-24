#include <bits/stdc++.h>
using namespace std;
string tmp;
int sum;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> tmp;
	for (int i = 0; i < tmp.size(); i++)
		sum += (tmp[i] - '0');
	sort(tmp.rbegin(), tmp.rend());
	if (sum % 3 == 0 && tmp[tmp.size()-1] == '0')
		cout << tmp;
	else
		cout << -1;
	return 0;
}
