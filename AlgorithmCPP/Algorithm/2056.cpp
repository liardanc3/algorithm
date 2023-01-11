#include <bits/stdc++.h>
using namespace std;
int N, tmp, M, finish[10001], w[10001];
vector<int> vect[10001];

int fun() {
	finish[1] = w[1];
	for (int i = 1; i <= N; i++) {
		int mx = 0;
		finish[i] = w[i];
		for (int j = 0; j < vect[i].size(); j++) {
			int parent = vect[i].at(j);
			finish[i] = max(finish[i], w[i] + finish[parent]);
		}

	}
	return *max_element(&finish[1], &finish[N + 1]);
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> w[i] >> M;
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			vect[i].push_back(tmp);
		}
	} 
	cout << fun();
	return 0;
}