#include <bits/stdc++.h>
using namespace std;
int N, tmp, arr[11]{ 0, }, cnt, idx, j, i;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		cnt = 0;
		for (j = 1; cnt<tmp; j++) {
			if(arr[j]==0)
				cnt++;
		}
		for (j = 1; idx < cnt; j++) {
			if (arr[j] == 0)
				idx++;
		}
		while (arr[j] != 0) 
			j++;
		arr[j] = i;
	}
	for (i = 1; i <= N; i++)
		cout << arr[i] << ' ';
	return 0;
}