#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, cmdcnt, tmp; char cmd;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> cmdcnt;
		multiset<int> ms;
		for (int j = 0; j < cmdcnt; j++) {
			cin >> cmd >> tmp;
			if (cmd == 'I')
				ms.insert(tmp);
			else {
				if (!ms.empty()) {
					if (tmp == -1)
						ms.erase(ms.begin());
					else {
						multiset<int>::iterator it = ms.end();
						it--;
						ms.erase(it);
					}
				}
			}
		}
		if (ms.empty()) 
			cout << "EMPTY\n";
		else {
			cout << *(--ms.end()) << " " << *(ms.begin()) << "\n";
		}
	}
	return 0;
}