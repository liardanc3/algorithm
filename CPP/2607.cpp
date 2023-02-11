#include <bits/stdc++.h>
using namespace std;

int N, cnt, origin[27], compar[27];
string str, tmp;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> str;
	for (int i = 0; i < str.size(); i++) 
		origin[str[i] - 'A']++;
	while (--N) {
		memset(compar, 0, sizeof(compar));
		cin >> tmp;

		int impossible = abs((int)str.size() - (int)tmp.size()) , dif = 0, unmatch = 0;
		[&]() {
			for (int i = 0; i < tmp.size(); i++)
				compar[tmp[i] - 'A']++;

			for (int i = 0; i < 26 && impossible < 2; i++) {
				if (origin[i] || compar[i]) {
					if (abs(origin[i] - compar[i]) <= 1)
						dif += abs(origin[i] - compar[i]);
					else
						impossible++;

					if (!origin[i] || !compar[i])
						unmatch++;
				}
			}
		}();
		
		if (impossible >= 2)
			continue;
		else if (dif <= 1)
			cnt++;
		else if (dif <= 2 && unmatch <= 2)
			cnt++;
	}
	cout << cnt;
	return 0;
}