#include <bits/stdc++.h>
using namespace std;

map<string, int> idx;
int t, F, tree[300001], idxcnt = 1, unioncnt[300001];
string ans, a, b;
int getRoot(int i) {
	return tree[i] == i ? i : tree[i] = getRoot(tree[i]);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	while (t--) {
		[&]() {
			cin >> F;
			fill(&unioncnt[0], &unioncnt[300001], 1);
			idxcnt = 1;
			idx.clear();
			for (int i = 1; i <= 300000; i++)
				tree[i] = i;
		}();
		while (F--) {
			cin >> a >> b;
			int idxa = idx[a];
			int idxb = idx[b];

			if (!idx[a]) {
				idx[a] = idxcnt++;
				idxa = idxcnt - 1;
			}
			if (!idx[b]) {
				idx[b] = idxcnt++;
				idxb = idxcnt - 1;
			}

			int cnt = 0;
			if (getRoot(idxa) == getRoot(idxb))
				cnt = unioncnt[idxa];
			else
				cnt = unioncnt[idxa] + unioncnt[idxb];
			
			tree[getRoot(idxa)] = getRoot(idxb);
			
			unioncnt[idxa] = cnt;
			unioncnt[idxb] = cnt;

			cout << cnt << '\n';
		}
	}
	return 0;
}