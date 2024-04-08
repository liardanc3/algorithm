#include <bits/stdc++.h>
using namespace std;

string ucpc, tmp;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	getline(cin, tmp);
	for(int i=0; i<tmp.size(); i++) {
		if (tmp[i] == 'U' && ucpc == "")
			ucpc += tmp[i];
		if (tmp[i] == 'C' && ucpc == "U")
			ucpc += tmp[i];
		if (tmp[i] == 'P' && ucpc == "UC")
			ucpc += tmp[i];
		if (tmp[i] == 'C' && ucpc == "UCP")
			ucpc += tmp[i];
	}
	if (ucpc == "UCPC")
		cout << "I love UCPC";
	else
		cout << "I hate UCPC";
	return 0;
}
