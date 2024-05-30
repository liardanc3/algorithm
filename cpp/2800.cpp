#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;
vector<string> ans;
string str;
stack<int> st;

int ck[201];
void solve(int bit) {
	memset(ck, 0, sizeof(ck));
	for (int i = 0; bit > 0; i++) {
		if (bit & 1) {
			ck[vect[i].first] = 1;
			ck[vect[i].second] = 1;
		}
		bit >>= 1;
	}
	string now = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' || str[i] == ')') {
			if (ck[i])
				now += str[i];
		}
		else
			now += str[i];
	}
	ans.push_back(now);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(')
			st.push(i);
		else if (str[i] == ')') {
			vect.push_back({ st.top(),i });
			st.pop();
		}
	}
	for (int i = 0; i < (1 << vect.size()) - 1; i++) 
		solve(i);
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (string s : ans)
		cout << s << '\n';
	return 0;
}