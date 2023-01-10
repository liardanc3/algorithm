#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, A, B, d[1001];
vector<int> vect[1001];

void fun() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < vect[i].size(); j++) {
			int parent = vect[i].at(j);
			d[i] = max(d[i], d[parent] + 1);
		}
	}
	for (int i = 1; i <= N; i++)
		cout << d[i]+1 << ' ';
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		vect[B].push_back(A);
	}
	fun();
	return 0;
}