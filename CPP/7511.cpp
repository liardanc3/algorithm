#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
int N, K, T, tmp1, tmp2;
int user[1000001];

int getRoot(int i) {
	if (user[i] != i)
		user[i] = getRoot(user[i]);
	return user[i];
}
void init() {
	for (int i = 0; i <= 1000000; i++)
		user[i] = i;
}
int main() {
	fastio;
	cin >> T;
	for(int t=1; t<=T; t++) {
		int root;
		init();
		cin >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> tmp1 >> tmp2;
			if (i == 0) {
				root = tmp1;
				user[getRoot(tmp2)] = tmp1;
			}
			else {
				if (tmp2 == root)
					user[getRoot(tmp1)] = root;
				else user[getRoot(tmp2)] = getRoot(tmp1);
			}
		}
		cin >> K;
		cout << "Scenario " << t << ":\n";
		for (int i = 0; i < K; i++) {
			cin >> tmp1 >> tmp2;
			if (getRoot(tmp1) == getRoot(tmp2))
				cout << "1\n";
			else cout << "0\n";
		}
		cout << '\n';
	}
	
	return 0;
}