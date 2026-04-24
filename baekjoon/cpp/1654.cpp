#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int K, N, tmp;
	cin >> K >> N;
	vector<int> utp;
	for (int i = 0; i < K; i++) {
		cin >> tmp;
		utp.push_back(tmp);
	}
	sort(utp.begin(), utp.end());
	long long left = 0;
	long long right = utp.at(K - 1);
	long long center, ans;
	long long sum, sum_tmp;
	while (true) {
		sum = 0;
		center = (left + right) / 2;
		if (center == 0) { ans = 1; break; }
		for (int i = 0; i < K; i++)
			sum += utp.at(i) / center;
		if (right <= left) {
			if (sum >= N) {
				sum_tmp = 0;
				for (int i = 0; i < K; i++)
					sum_tmp += utp.at(i) / (center + 1);
				if (sum_tmp >= N) ans = center + 1;
				else ans = center;
				break;
			}
		}
		if (sum >= N) left = center + 1;
		if (center == 1) { ans = center; break; }
		if (sum < N) right = center - 1;

	}
	cout << ans;
	return 0;
}