#include <bits/stdc++.h>
#define MX 1'000'000'000
#define int long long
using namespace std;

typedef pair<string, int> psi;

string cmd, ans="";
vector<psi> vect;
int num, n;
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	while (cin >> cmd) {
		vect.clear();
		if (cmd == "QUIT")
			break;

		while (cmd != "END") {
			if (cmd == "NUM") {
				cin >> num;
				vect.push_back({ cmd,num });
			}
			else
				vect.push_back({ cmd,0 });
			cin >> cmd;
		}

		cin >> n;
		while (n--) {
			stack<int> st;
			cin >> num;
			st.push(num);
			bool error = false;
			for (int i = 0; i < vect.size(); i++) {
				if (vect[i].first == "NUM")
					st.push(vect[i].second);
				else if (vect[i].first == "POP") {
					if (st.empty()) {
						error = true;
						break;
					}
					st.pop();
				}
				else if (vect[i].first == "INV") {
					if (st.empty()) {
						error = true;
						break;
					}
					int t = st.top(); st.pop();
					st.push(-t);
				}
				else if (vect[i].first == "DUP") {
					if (st.empty()) {
						error = true;
						break;
					}
					st.push(st.top());
				}
				else if (vect[i].first == "SWP") {
					if (st.size() < 2) {
						error = true;
						break;
					}
					int a = st.top(); st.pop();
					int b = st.top(); st.pop();
					st.push(a);
					st.push(b);
				}
				else if (vect[i].first == "ADD") {
					if (st.size() < 2) {
						error = true;
						break;
					}
					int a = st.top(); st.pop();
					int b = st.top(); st.pop();
					if (abs(a + b) > MX) {
						error = true;
						break;
					}
					st.push(a + b);
				}
				else if (vect[i].first == "SUB") {
					if (st.size() < 2) {
						error = true;
						break;
					}
					int a = st.top(); st.pop();
					int b = st.top(); st.pop();
					if (abs(b - a) > MX) {
						error = true;
						break;
					}
					st.push(b - a);
				}
				else if (vect[i].first == "MUL") {
					if (st.size() < 2) {
						error = true;
						break;
					}
					int a = st.top(); st.pop();
					int b = st.top(); st.pop();
					if (abs(a * b) > MX) {
						error = true;
						break;
					}
					st.push(a * b);
				}
				else if (vect[i].first == "DIV") {
					if (st.size() < 2) {
						error = true;
						break;
					}
					int a = st.top(); st.pop();
					int b = st.top(); st.pop();
					if (a == 0) {
						error = true;
						break;
					}
					int c = abs(b) / abs(a);
					if ((a < 0 && b>0) || (a > 0 && b < 0))
						st.push(-c);
					else
						st.push(c);
				}
				else {
					if (st.size() < 2) {
						error = true;
						break;
					}
					int a = st.top(); st.pop();
					int b = st.top(); st.pop();
					if (a == 0) {
						error = true;
						break;
					}
					int c = abs(b) % abs(a);
					if (b < 0)
						st.push(-c);
					else
						st.push(c);
				}
			}
			if (error || st.size() != 1)
				ans += "ERROR\n";
			else
				ans += to_string(st.top()) + '\n';
		}
		ans += '\n';
	}
	cout << ans;
	return 0;
}