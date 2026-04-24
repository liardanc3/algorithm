#include <bits/stdc++.h>
using namespace std;

int N, M, K;
set<string> s;
map<string, int> m;
map<int, string> rev;
vector<string> vect[1001], idx;
string tmp;
struct TRIE {
	bool final;
	TRIE* node[1001];
	TRIE() {
		final = false;
		for (int i = 0; i <= 1000; i++)
			node[i] = NULL;
	}

	void insert(int i, int pos) {
		vector<string> v = vect[i];
		if (pos == v.size()) {
			final = true;
			return;
		}
		int now = m[v[pos]];

		if (node[now] == NULL)
			node[now] = new TRIE();
		node[now]->insert(i, pos + 1);
		return;
	}

	void find(int depth) {
		for (int i = 1; i <= m.size(); i++) {
			if (node[i] != NULL) {
				for (int j = 0; j < depth; j++)
					cout << "--";
				cout << rev[i] << '\n';
				if(!node[i]->final)
					node[i]->find(depth + 1);
			}
		}
		return;
	}
};
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> K;
		for (int j = 1; j <= K; j++) {
			cin >> tmp;
			vect[i].push_back(tmp);
			s.insert(tmp);
		}
	}
	for (string str : s)
		idx.push_back(str);
	sort(idx.begin(), idx.end());
	for (int i = 0; i < idx.size(); i++) {
		m[idx[i]] = i + 1;
		rev[i + 1] = idx[i];
	}
	TRIE root = TRIE();
	for (int i = 1; i <= N; i++)
		root.insert(i,0);
	root.find(0);
	return 0;
}