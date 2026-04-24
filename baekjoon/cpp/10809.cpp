#include <bits/stdc++.h>
using namespace std;
int arr[123];
int main() {
	fill(&arr[0], &arr[123], -1);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if(arr[s[i]]==-1)
			arr[s[i]] = i;
	}
		
	for (int i = 97; i <= 122; i++)
		cout << arr[i] << ' ';
	return 0;
}