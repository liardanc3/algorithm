#include <bits/stdc++.h>
using namespace std;
int N, ck[15]{ 0, }, arr[15], ans;
int dy[]{ 1,1 };
int dx[]{ 1,-1 };

void bt(int cnt) {
	if (cnt == N) {
		ans++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (ck[i] == 0) {
			if (cnt == 0) arr[cnt] = i;
			else {
				int pos = 1;
				for (int j = 0; j < cnt; j++) {
					if (pos == 0) break;
					int y = j;
					int x = arr[j];
					int range = cnt - j;
					for (int k = 0; k < 2; k++) {
						int ddx = x + dx[k] * range;
						int ddy = y + dy[k] * range;
						if (cnt == ddy && i == ddx)
							pos = 0;
					}
				}
				if (pos == 0) continue;
			}
			ck[i] = 1;
			arr[cnt] = i;
			cnt++;
			bt(cnt);
			cnt--;
			ck[i] = 0;
		}		
	}
	return;
}

int main() {
	cin >> N; ans = 0;
	bt(0); cout << ans;
	return 0;
}