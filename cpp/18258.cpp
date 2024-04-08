#include <bits/stdc++.h>
using namespace std;

int N, num;
string cmd;
queue<int> q;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> num;
			q.push(num);
		}
		else {
			if (cmd == "front") {
				if (q.empty())
					cout << -1 << '\n';
				else
					cout << q.front() << '\n';
			}
			else if (cmd == "back") {
				if (q.empty())
					cout << -1 << '\n';
				else
					cout << q.back() << '\n';
			}
			else if (cmd == "size")
				cout << q.size() << '\n';
			else if (cmd == "pop") {
				if (q.empty())
					cout << -1 << '\n';
				else {
					cout << q.front() << '\n';
					q.pop();
				}
			}
			else 
				q.empty() ? cout << "1\n" : cout << "0\n";				
		}
	}
	return 0;
}
