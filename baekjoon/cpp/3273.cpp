#include <bits/stdc++.h>
using namespace std;

int n, tmp, x, cnt, arr[1'000'001];
vector<int> vect;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr[tmp]++;
	}
	cin >> x;
	
	for (int i = 1; i <= min(1'000'000,x/2); i++) {
		int left = i;
		int right = x - i;

		if (left <= 1'000'000 && right <= 1'000'000) {
			if (arr[left] && arr[right])
				cnt++;
		}
	}
	cout << cnt;
	return 0;
}
