#include <bits/stdc++.h>
using namespace std;
string s;
vector<char> vect;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> s;
	int top = -1;
	for (int i = 0; i < s.size(); i++) {
		char now = s[i];
		vect.push_back(now);
		top++;

		if (vect.size() >= 4) {
			bool flag = (vect[top - 3] == 'P' && vect[top - 2] == 'P' && vect[top - 1] == 'A' && vect[top] == 'P');
			while (flag) {
				vect.erase(vect.begin() + top - 3, vect.begin() + top);
				top = vect.size() - 1;
				flag = false;
				if(top >= 3)
					flag = (vect[top - 3] == 'P' && vect[top - 2] == 'P' && vect[top - 1] == 'A' && vect[top] == 'P');
			}
		}
	}
	if (vect[0] == 'P' && vect.size() == 1)
		cout << "PPAP";
	else cout << "NP";
	return 0;
}