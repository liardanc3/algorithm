#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, tmp;
	int ans = 0;
	cin >> N;
	vector<int> vect;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	int sum = 0;
	for (auto it = vect.begin(); it != vect.end(); it++) {
		ans += *it + sum;
		sum += *it;
	}
	cout << ans << "\n";
	return 0;
}