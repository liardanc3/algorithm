#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> vect;
	int N, M, L, tmp;
	cin >> N >> M >> L;
	vect.push_back(0);
	vect.push_back(L);
	for (int i = 0; i < N; i++) {
		cin >> tmp; 
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	//제일 먼곳을 제일 좁게

	int left = 1, right = L-1, mid, ans=0, cnt;
	while (left <= right) {
		cnt = 0;
		mid = (left + right) / 2;
		for (int i = 1; i < vect.size(); i++) {
			int div = (vect[i] - vect[i - 1])/mid;
			if ((vect[i] - vect[i - 1]) % mid == 0)
				div--;
			if (div > 0) {
				cnt += div;
			}
		}
		if (cnt > M) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << left;

	return 0;
}