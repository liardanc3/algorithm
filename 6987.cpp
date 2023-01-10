#include <bits/stdc++.h>
using namespace std;
int arr[7][4], play[7][4];
int dfs(int a,int b) {
	if (a == 6) {
		for (int i = 1; i <= 6; i++) {
			for (int j = 1; j <= 3; j++) {
				if (arr[i][j] != play[i][j])
					return 0;
			}
		}
		return 1;
	}

	int ret = 0;

	// aÆÀ½Â¸® bÆÀÆÐ¹è
	if (play[a][1] < arr[a][1] && play[b][3] < arr[b][3]) {
		play[a][1]++, play[b][3]++;
		
		if (b == 6) ret = max(ret, dfs(a + 1, a + 2));
		else ret = max(ret, dfs(a, b + 1));
	
		play[a][1]--, play[b][3]--;
	}

	// aÆÀÆÐ¹è bÆÀ½Â¸®
	if (play[a][3] < arr[a][3] && play[b][1] < arr[b][1] && !ret) {
		play[a][3]++, play[b][1]++;

		if (b == 6) ret = max(ret, dfs(a + 1, a + 2));
		else ret = max(ret, dfs(a, b + 1));

		play[a][3]--, play[b][1]--;
	}

	// aÆÀ bÆÀ ¹«½ÂºÎ
	if (play[a][2] < arr[a][2] && play[b][2] < arr[b][2] && !ret) {
		play[a][2]++, play[b][2]++;

		if (b == 6) ret = max(ret, dfs(a + 1, a + 2));
		else ret = max(ret, dfs(a, b + 1));

		play[a][2]--, play[b][2]--;
	}

	return ret;
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 6; j++) for (int k = 1; k <= 3; k++)
			cin >> arr[j][k];
		memset(play, 0, sizeof(play));
		cout << dfs(1,2) << ' ';
	}
	return 0;
}