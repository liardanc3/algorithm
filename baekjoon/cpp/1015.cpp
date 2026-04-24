#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, tmp;
	cin >> n;
	vector<int> v1, v2;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v1.push_back(tmp);
		v2.push_back(tmp);
	}
	sort(v2.begin(), v2.end());
	int arr[1001]{ 0, };
	for (int now : v1) {
		for (int i = 0; i < v2.size(); i++) {
			if (now == v2[i]) {
				cout << i + arr[now] << ' ';
				arr[now]++;
				break;
			}
		}
	}
	return 0;
}