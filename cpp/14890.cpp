#include <bits/stdc++.h>
using namespace std;

double N, L, arr[101][101], cnt, tmp[101], visited[101];

bool slope(int idx, int right) {
	double mn = 1e9, mx = -1;

	if (right) {
		if (idx + L - 1 > N) return false;
		for (int i = idx; i < idx + L; i++)
			mn = min(mn, tmp[i]), mx = max(mx, tmp[i]);
		if (mn != mx)
			return false;
		for (int i = idx; i < idx + L; i++) {
			if (visited[i]) return false;
			visited[i] = 1;
		}
		for (int i = idx; i < idx + L - 1; i++)
			tmp[i] += 0.5;
		return true;
	}
	else {
		if (idx - L + 1 < 1) return false;
		for(int i=idx-L+1; i<=idx; i++)
			mn = min(mn, tmp[i]), mx = max(mx, tmp[i]);
		if (mn != mx)
			return false;
		for (int i = idx - L + 1; i <= idx; i++) {
			if (visited[i]) return false;
			visited[i] = 1;
		}
		for (int i = idx - L + 2; i <= idx; i++)
			tmp[i] += 0.5;
		return true;
	}
}

void ck(int r, int c) {
	memset(visited, 0, sizeof(visited));
	if (r) {

		// 행 전체 동일
		double mn = 11, mx = 0;
		for (int i = 1; i <= N; i++) 
			mn = min(mn, arr[r][i]), mx = max(mx, arr[r][i]);
		if (mn == mx) {
			cnt++;
			return;
		}

		memset(tmp, 0, sizeof(tmp));
		for (int i = 1; i <= N; i++)
			tmp[i] = arr[r][i];
		
		// 좌우 2칸이상 X
		double gap = 0;
		for (int i = 1; i < N; i++)
			gap = max(gap, abs(tmp[i] - tmp[i + 1]));
		if (gap > 1)
			return;

		// 경사로 
		bool flag = true;
		for (int i = 1; i <= N && flag; i++) {
			if (tmp[i] == tmp[i + 1] + 1 && i + 1 <= N)
				flag = slope(i + 1, 1);
			if (tmp[i] + 1 == tmp[i + 1] && i + 1 <= N)
				flag = slope(i, 0);
		}

		gap = 0;
		for (int i = 1; i < N; i++)
			gap = max(gap, abs(tmp[i + 1] - tmp[i]));

		if (L > 1) {
			if (gap <= 0.5 && flag)
				cnt++;
		}
		else {
			if (gap <= 1 && flag)
				cnt++;
		}
	}
	if (c) {

		// 열 전체 동일
		double mn = 11, mx = 0;
		for (int i = 1; i <= N; i++)
			mn = min(mn, arr[i][c]), mx = max(mx, arr[i][c]);
		if (mn == mx) {
			cnt++;
			return;
		}

		memset(tmp, 0, sizeof(tmp));
		for (int i = 1; i <= N; i++)
			tmp[i] = arr[i][c];

		// 좌우 2칸이상 X
		double gap = 0;
		for (int i = 1; i < N; i++)
			gap = max(gap, abs(tmp[i] - tmp[i + 1]));
		if (gap > 1)
			return;

		// 경사로 
		bool flag = true;
		for (int i = 1; i <= N && flag; i++) {
			if (tmp[i] == tmp[i + 1] + 1 && i+1<=N)
				flag = slope(i + 1, 1);
			if (tmp[i] + 1 == tmp[i + 1] && i+1<=N)
				flag = slope(i, 0);
		}

		gap = 0;
		for (int i = 1; i < N; i++)
			gap = max(gap, abs(tmp[i + 1] - tmp[i]));

		if (L > 1) {
			if (gap <= 0.5 && flag)
				cnt++;
		}
		else {
			if (gap <= 1 && flag)
				cnt++;
		}
	}
}
void init() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> L;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
		cin >> arr[i][j];
}
int main() {
	init();
	for (int i = 1; i <= N; i++) {
		ck(0, i);
		ck(i, 0);
	}
	cout << cnt;
	return 0;
}