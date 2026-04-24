#include <bits/stdc++.h>
using namespace std;

vector<string> vect;
int N, cnt;
struct TRIE {
	bool finish;
	TRIE* node[26];
	TRIE() {
		finish = 0;
		for (int i = 0; i <= 25; i++)
			node[i] = NULL;
	}
	~TRIE() {
		for (int i = 0; i <= 25; i++)
			if (node[i])
				delete node[i];
	}
	void insert(string str, int idx) {
		if (idx == str.size()) {
			finish = true;
			return;
		}
		int now = str[idx] - 'a';
		if (node[now] == NULL)
			node[now] = new TRIE();
		node[now]->insert(str, idx + 1);
	}
	void solve(int len) {
		if (finish)
			cnt += len;

		vector<int> next;
		for (int i = 0; i <= 25; i++) {
			if (node[i] != NULL)
				next.push_back(i);
		}
		if (next.size() == 1 && finish == false)
			node[next[0]]->solve(len);
		else {
			for (int j = 0; j < next.size(); j++)
				node[next[j]]->solve(len + 1);
		}
	}
};
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	while (cin >> N) {
		if (cin.eof())
			break;
		[&]() {
			cnt = 0;
			vect.clear();
			string tmp;
			for (int i = 0; i < N; i++) {
				cin >> tmp;
				vect.push_back(tmp);
			}
			sort(vect.begin(), vect.end());
			int idx = 0;
			for (int i = 0; i <= 25 && idx < vect.size(); i++) {
				if (vect[idx][0] == i + 'a') {
					TRIE trie = TRIE();
					for (int j = idx; j < vect.size(); j++) {
						if (vect[j][0] == i + 'a')
							trie.insert(vect[j], 0);
						else {
							idx = j;
							break;
						}
					}
					trie.solve(1);
				}
			}
			cout << fixed;
			cout.precision(2);
			cout << (double)((double)cnt / (double)N) << '\n';
		}();
	}
	return 0;
}