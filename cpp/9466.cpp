#include <bits/stdc++.h>
using namespace std;
int tree[100001], ck[100001], cnt;
typedef pair<int, int> pii;
void getRoot(int i, int start) {
	int size = 0;
	vector<int> vect;
	do {
		vect.push_back(i);
		ck[i] = 1;
		i = tree[i];
		size++;
	} while (i != tree[i] && ck[i] != 1);
	vect.push_back(i);
	if (ck[i] == 0) {
		cnt += 1;
		ck[i] = 1;
	}
	else {
		if (i == start) cnt += size;
		else {
			int dn;
			for (int j = 0; j < vect.size(); j++) {
				if (vect[j] == i) {
					dn = j; break;
				}
			}
			if (dn != vect.size() - 1)
				cnt += vect.size() - dn -1;
		}
	}
}

void disjoint(int n) {
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (ck[i] == 0) getRoot(i, i);
	}
	cout << n - cnt << '\n';
}

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, n; cin >> T;
	while (T--) {
		memset(ck, 0, sizeof(ck));
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> tree[i];
		disjoint(n);
	}
}

int main() {
	init();
	return 0;
}