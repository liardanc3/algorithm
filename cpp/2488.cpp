#include <bits/stdc++.h>
using namespace std;
vector<int> A, B;
int a, b, tmp;
void solve() {
	int left = 0, right = 50;
	vector<int> ansA,ansB;
	while (left <= right) {
		vector<int> tmpA,tmpB;
		int mid = (left + right) / 2;
		int cnt = 0;
		int Asum = A[0], Bsum = B[0];
		int Aidx = 1, Bidx = 1;
		while (Aidx < A.size() && Bidx < B.size()) {
			while (Aidx < A.size() && Bidx < B.size() && abs(Asum - Bsum) <= mid) {
				tmpA.push_back(Aidx);
				tmpB.push_back(Bidx);
				Asum = A[Aidx++], Bsum = B[Bidx++];
				cnt++;
			}
			if (Aidx < A.size() && Bidx < B.size() && Asum < Bsum)
				Asum += A[Aidx++];
			else if (Aidx < A.size() && Bidx < B.size() && Asum > Bsum)
				Bsum += B[Bidx++];
		}
		while (Aidx < A.size())
			Asum += A[Aidx++];
		while (Bidx < B.size())
			Bsum += B[Bidx++];
		if (abs(Asum - Bsum) > mid) {
			right = mid - 1;
		}
		else {
			if (cnt >= 2) {
				left = mid + 1;
			}
			else right = mid - 1;
		}
	}
	for (int i = 0; i < ansA.size(); i++)
		cout << ansA[i] << ' ';
	cout << '\n';
	for (int i = 0; i < ansB.size(); i++)
		cout << ansB[i] << ' ';
	cout << left;
}


void init() {
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> tmp;
		A.push_back(tmp);
	}
	for (int i = 0; i < b; i++) {
		cin >> tmp;
		B.push_back(tmp);
	}
	solve();
}
int main() {
	init();
	return 0;
}