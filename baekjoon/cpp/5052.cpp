#include <bits/stdc++.h>
#define int long long
using namespace std;

int T, n;
vector<string> vect;
string num, tmp;

struct TRIE {
	bool finish;
	TRIE *Node[10];
	TRIE() {
		finish = false;
		for (int i = 0; i < 10; i++)
			Node[i] = NULL;
	}

	void insert(string number, int idx) {
		int now = number[idx] - '0';

		if (Node[now] == NULL)
			Node[now] = new TRIE();
		if (idx + 1 == number.size()) {
			Node[now]->finish = true;
			return;
		}
		else 
			Node[now]->insert(number, idx + 1);
		return;
	}

	bool find(string number, int idx) {
		int now = number[idx] - '0';
		
		if (Node[now]->finish == true) {
			if (idx == number.size() - 1)
				return true;
			else
				return false;
		}

		return Node[now]->find(number, idx + 1);
	}
};

signed main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	while (T--) {
		TRIE root = TRIE();
		vect.clear();
		cin >> n;
		while (n--) {
			cin >> tmp;
			vect.push_back(tmp);
			root.insert(tmp, 0);
		}
		for (int i = 0; i < vect.size(); i++) {
			if (!root.find(vect[i], 0)) {
				cout << "NO\n";
				break;
			}
			if (i == vect.size() - 1) 
				cout << "YES\n";
		}
	}
	return 0;
}