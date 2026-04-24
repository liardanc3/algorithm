#include <bits/stdc++.h>
using namespace std;

string str;
int K, visited[20000], p;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> K >> K >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'H')
			continue;
		for (int j = max(0, i - K); j <= i + K && j < str.size(); j++) {
			if (!visited[j] && str[j] == 'H') {
				visited[j] = 1;
				p++;
				cout << i << " : get " << j << '\n';
				break;
			}
		}
	}
	cout << p;
	return 0;
}