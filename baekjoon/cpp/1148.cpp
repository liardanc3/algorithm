#include <bits/stdc++.h>
using namespace std;
int arr[100]{ 0, };
vector<string> vect;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string now;
	while (cin >> now) {
		if (now == "-")
			break;
		vect.push_back(now);
	}
	while (cin >> now) {
		memset(arr, 0, sizeof(arr));
		if (now == "#")
			break;
		int tmp[100]{ 0, };
		for (int i = 0; i < now.size(); i++) 
			tmp[now[i]]++;
		for (int i = 0; i < vect.size(); i++) {
			int _tmp[100];
			copy(&tmp[0], &tmp[100], &_tmp[0]);
			vector<int> cnt;
			for (int j = 0; j < vect[i].size(); j++) {
				int ch = vect[i][j];
				if (_tmp[ch] > 0) {
					_tmp[ch]--;
					cnt.push_back(ch);
				}
				else {
					cnt.clear();
					break;
				}
			}
			sort(cnt.begin(), cnt.end());
			cnt.erase(unique(cnt.begin(), cnt.end()), cnt.end());

			for (int j = 0; j < cnt.size(); j++)
				arr[cnt[j]]++;
		}
		vector<int> vmn, vmx;
		int mn = 1e9, mx = -1e9;
		for (int i = 0; i < now.size(); i++) {
			int ch = now[i];
			if (arr[ch] < mn) {
				vmn.clear();
				vmn.push_back(ch);
				mn = arr[ch];
			}
			else if (arr[ch] == mn) 
				vmn.push_back(ch);

			if (arr[ch] > mx) {
				vmx.clear();
				vmx.push_back(ch);
				mx = arr[ch];
			}
			else if (arr[ch] == mx)
				vmx.push_back(ch);
		}
		sort(vmn.begin(), vmn.end());
		vmn.erase(unique(vmn.begin(), vmn.end()), vmn.end());

		sort(vmx.begin(), vmx.end());
		vmx.erase(unique(vmx.begin(), vmx.end()), vmx.end());

		for (int i = 0; i < vmn.size(); i++)
			cout << (char)vmn[i];
		cout << ' ' << mn << ' ';

		for (int i = 0; i < vmx.size(); i++)
			cout << (char)vmx[i];
		cout << ' ' << mx << '\n';
	}
	return 0;
}