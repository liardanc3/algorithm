#include <bits/stdc++.h>
using namespace std;
int cmd, num;
int N, M, K, a, b, now[100001], in[100001];
vector<int> vect[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		vect[a].push_back(b);
		in[b]++;
	}
	for (int i = 0; i < K; i++) {
		cin >> cmd >> num;

		if (cmd == 1) {
			if (in[num] > 0) {
				cout << "Lier!";
				return 0;
			}
			if (now[num] == 0) {
				for (int j = 0; j < vect[num].size(); j++)
					in[vect[num].at(j)]--;
			}
			now[num]++;
		}
		else {
			if (now[num] == 0) {
				cout << "Lier!";
				return 0;
			}
			now[num]--;
			if (now[num] == 0) {
				for (int j = 0; j < vect[num].size(); j++)
					in[vect[num].at(j)]++;
			}
		}
	}
	cout << "King-God-Emperor";
	return 0;
}