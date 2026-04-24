#include <bits/stdc++.h>
using namespace std;
int n, arr[500001], rasor[500001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		for (int j = i - 1; j >= 1; j--) {
			if (arr[j] > arr[i]) {
				rasor[i] = j;
				break;
			}
			if (arr[j] <= arr[i]) {
				if (arr[rasor[j]] > arr[i]) {
					rasor[i] = rasor[j];
					break;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << rasor[i] << ' ';
	return 0;
}