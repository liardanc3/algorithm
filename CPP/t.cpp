#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int N, M, tmp;
vector<pii> v1, v2;
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		v1.push_back({ tmp,i });
		if (i == N)
			v2.push_back({ tmp,1 });
	}
	for (int i = 2; i <= M; i++) {
		cin >> tmp;
		v2.push_back({ tmp,i });
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	cout << v1[0].second << ' ' << v2[0].second;
	return 0;
}