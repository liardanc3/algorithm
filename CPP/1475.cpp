#include <bits/stdc++.h>
using namespace std;
int arr[10]{ 0, };
int main() {
	string n; cin >> n;
	for (int i = 0; i < n.size(); i++) {
		int now = n[i] - '0';
		if (now == 6 || now == 9) {
			if (arr[6] < arr[9]) arr[6]++;
			else arr[9]++;
		}
		else arr[now]++;
	}
	cout << *max_element(&arr[0], &arr[10]);
	return 0;
}