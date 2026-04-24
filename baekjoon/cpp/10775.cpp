#include <bits/stdc++.h>
using namespace std;
int G, P, g, airport[100001], ck[100001];
int main() {
	cin >> G >> P;
	for (int i = 1; i <= G; i++)
		airport[i] = i;
	int flag = 0, ans=0;
	for (int i = 1; i <= P; i++) {
		cin >> g;
		if (!flag) {
			while (ck[airport[g]] != 0) 
				airport[g]--;
			if (airport[g] == 0)
				flag = 1;
			else {
				ck[airport[g]--] = 1;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}