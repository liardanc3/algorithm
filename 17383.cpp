#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<int> vect;
	int N, T;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T;
		vect.push_back(T);
	} sort(vect.begin(), vect.end());

	int left = 1, right = vect[N - 1];
	while (left <= right) {
		int mid = (left + right) / 2;

		vector<int> arr;
		for (int i = 0; i < N; i++) {
			int tmp = vect[i] / mid;
			if (vect[i] % mid == 0)
				tmp--;
			tmp++;
			arr.push_back(tmp);
		} sort(arr.begin(), arr.end());

		int cnt = 0;
		if (arr[0] > 1) cnt = -1;
		else {
			for (int i = 1; i < N; i++) {
				if (arr[i] == 1) cnt++;
				else cnt -= (arr[i] - 2);
			}
		}
		if (cnt >= 0)
			right = mid - 1;
		else
			left = mid + 1;
	}
	cout << left;
	return 0;
}