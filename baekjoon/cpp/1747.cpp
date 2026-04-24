#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> vect;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	if (N <= 2) {
		cout << 2;
		exit(0);
	}
	vect.push_back(2);
	for (int i = 3;; i += 2) {
		int prime = 1;
		for (int j = 0; prime && j < vect.size() && vect[j]*vect[j] <= i; j++) {
			if (i % vect[j] == 0)
				prime = 0;
		}
		if (prime) {
			vect.push_back(i);
			if (i >= N) {
				string now = to_string(i);
				int fd = 1;
				for (int i = 0; i < now.size() / 2 && fd; i++) {
					if (now[i] != now[now.size() - 1 - i])
						fd = 0;
				}
				if (fd) {
					cout << i;
					exit(0);
				}
			}
		}
	}
	return 0;
}