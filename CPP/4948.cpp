#include <bits/stdc++.h>
using namespace std;

int n, prime[246913], prefix[246913];
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		fill(&prime[0], &prime[246913], 1);
		for (int i = 2; i * i <= 246912; i++) {
			if (!prime[i])
				continue;
			else {
				int now = i + i;
				while (now < 246913) {
					prime[now] = 0;
					now += i;
				}
			}
		}
		for (int i = 2; i <= 246912; i++)
			prefix[i] = prefix[i - 1] + prime[i];
	}();
	
	while (cin >> n) {
		if (!n)
			break;
		cout << prefix[2 * n] - prefix[n] << '\n';
	}
	return 0;
}