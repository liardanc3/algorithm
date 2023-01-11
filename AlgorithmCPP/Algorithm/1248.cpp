#include <bits/stdc++.h>
using namespace std;
string str; char S[11][11];
int N, A[11]{ 0, }, visited[21]{ 0, };

bool correct(int now) {
	for (int i = 0; i < now; i++) {
		for (int j = i; j < now; j++) {
			int sum = 0;
			for (int k = i; k <= j; k++)
				sum += A[k];
			if (sum > 0 && S[i][j] != '+')
				return false;
			if (sum == 0 && S[i][j] != '0')
				return false;
			if (sum < 0 && S[i][j] != '-')
				return false;
		}
	}
	return true;
}

void bt(int now) {
	if (now == N) {
		for (int i = 0; i < now; i++)
			cout << A[i] << ' ';
		exit(0);
	}
	if (S[now][now] == '0') {
		if (visited[10]) return;
		visited[10] = 1;
		A[now] = 0;
		if(correct(now+1))
			bt(now + 1);
		visited[10] = 0;
	}
	if (S[now][now] == '+') {
		for (int i = 1; i <= 10; i++) {
			if (visited[i + 10]) continue;
			visited[i + 10] = 1;
			A[now] = i;
			if (correct(now + 1))
				bt(now + 1);
			visited[i + 10] = 0;
		}
	}
	if (S[now][now] == '-') {
		for (int i = -10; i <= -1; i++) {
			if (visited[i + 10]) continue;
			visited[i + 10] = 1;
			A[now] = i;
			if (correct(now + 1))
				bt(now + 1);
			visited[i + 10] = 0;
		}
	}
	return;
}

int main() {
	cin >> N >> str;
	int idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++)
			S[i][j] = str[idx++];
	}
	bt(0);
	return 0;
}