#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int arr[2000001]{ 0, }, C, N, money, client;
int main() {
	vector<pii> vect;
	//fill(&arr[0], &arr[2500], 1e9);
	cin >> C >> N;
	while (N--) {
		cin >> money >> client;
		arr[money] = max(arr[money], client);
		vect.push_back(pii(money, client));
	}
	for (int i = 0;; i++) {
		for (int j = 0; j <= vect.size(); j++) {
			int pay = i + vect[j].first;
			int client = arr[i] + vect[j].second;
			arr[pay] = max(arr[pay], client);
		}
		if (arr[i] >= C) {
			cout << i;
			break;
		}
	}
	return 0;
}