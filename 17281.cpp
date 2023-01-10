#include <bits/stdc++.h>
using namespace std;
int n, arr[51][10], mx, cnt, idx, ground[4], point, last;
vector<int> origin, vect;
void baseball() {
	vect.clear();
	for (int i = 0; i < 3; i++)
		vect.push_back(origin[i]);
	vect.push_back(1);
	for (int i = 3; i < 8; i++)
		vect.push_back(origin[i]);
	idx = -1, point = 0;
	for (int i = 1; i <= n; i++) {
		memset(ground, 0, sizeof(ground));
		cnt = 0;
		while (cnt < 3) {
			idx = (idx + 1) % 9;
			last = vect[idx];

			int result = arr[i][last];

			if (result == 1) {
				point += ground[3];
				ground[3] = ground[2];
				ground[2] = ground[1];
				ground[1] = 1;
			}
			else if (result == 2) {
				point += ground[3] + ground[2];
				ground[3] = ground[1];
				ground[2] = 1;
				ground[1] = 0;
			}
			else if (result == 3) {
				point += ground[3] + ground[2] + ground[1];
				ground[3] = 1;
				ground[2] = 0;
				ground[1] = 0;
			}
			else if(result==4){
				point += ground[3] + ground[2] + ground[1] + 1;
				memset(ground, 0, sizeof(ground));
			}
			else {
				cnt++;
			}
		}
	}
	mx = max(mx, point);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 9; j++)
			cin >> arr[i][j];
	}
	for (int i = 2; i <= 9; i++) 
		origin.push_back(i);
	do {
		baseball();
	} while (next_permutation(origin.begin(), origin.end()));
	cout << mx;
	return 0;
}