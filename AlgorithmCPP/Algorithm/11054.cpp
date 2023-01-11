#include <bits/stdc++.h>
using namespace std;
int N;
int A[1001];
vector<int> dp_mx;
vector<int> dp_min;
void make_dp() {
	for (int i = 1; i <= N; i++) {
		for (int j = i-1; j >= 1; j--) {
			if (A[i] > A[j])
				dp_mx.at(i) = max(dp_mx.at(i), dp_mx.at(j) + 1);
		}
	}
	for (int i = N; i >= 1; i--) {
		for (int j = i+1; j <= N; j++) {
			if (A[j] < A[i])
				dp_min.at(i) = max(dp_min.at(i), dp_min.at(j) + 1);
		}
	}
}
int main() {
	cin >> N;
	dp_mx.push_back(0);
	dp_min.push_back(0);
	int tmp;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		dp_mx.push_back(1);
		dp_min.push_back(1);
	}
	dp_mx.push_back(0);
	dp_min.push_back(0);
	make_dp();
	int mx = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = i + 1; j <= N + 1; j++) {
			int now = dp_mx.at(i) + dp_min.at(j);
			if (now > mx && A[i] != A[j])
				mx = now;
		}
	}
	cout << mx;
	return 0;
}