#include <bits/stdc++.h>
using namespace std;
int N, mx = 0;
bool check(int arr[][21], int arr_tmp[][21]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] != arr_tmp[i][j])
				return true;
		}
	}
	return false;
}
void dfs(int arr[][21], int cnt) {
	int arr_tmp[21][21]{ 0, };
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
		mx = max(mx, arr[i][j]);
	}
	if (cnt < 5) {
		//up
		copy(&arr[0][0], &arr[20][21], &arr_tmp[0][0]);
		for (int i = 1; i <= N; i++) {
			stack<int> s;
			for (int j = 1; j <= N; j++) {
				int now = arr[j][i];
				if (now == 0) continue;
				if (!s.empty() && s.top() == now) {
					s.pop();
					now = arr[j][i] * 2;
					s.push(now);
					s.push(0);
				}
				else s.push(now);
			}
			stack<int> st;
			while (!s.empty()) {
				if(s.top()!=0)
					st.push(s.top());
				s.pop();
			}
			for (int j = 1; j <= N; j++) {
				if (!st.empty()) {
					arr_tmp[j][i] = st.top();
					st.pop();
				}
				else
					arr_tmp[j][i] = 0;
			}
		}
		if(check(arr,arr_tmp)) dfs(arr_tmp, cnt + 1);

		// left 
		copy(&arr[0][0], &arr[20][21], &arr_tmp[0][0]);
		for (int i = 1; i <= N; i++) {
			stack<int> s;
			for (int j = 1; j <= N; j++) {
				int now = arr[i][j];
				if (now == 0) continue;
				if (!s.empty() && s.top() == now) {
					s.pop();
					now = arr[i][j] * 2;
					s.push(now);
					s.push(0);
				}
				else s.push(now);
			}
			stack<int> st;
			while (!s.empty()) {
				if (s.top() != 0)
					st.push(s.top());
				s.pop();
			}
			for (int j = 1; j <= N; j++) {
				if (!st.empty()) {
					arr_tmp[i][j] = st.top();
					st.pop();
				}
				else
					arr_tmp[i][j] = 0;
			}
		}
		if (check(arr, arr_tmp)) dfs(arr_tmp, cnt + 1);


		// right
		copy(&arr[0][0], &arr[20][21], &arr_tmp[0][0]);
		for (int i = 1; i <= N; i++) {
			stack<int> s;
			for (int j = N; j >= 1; j--) {
				int now = arr[i][j];
				if (now == 0) continue;
				if (!s.empty() && s.top() == now) {
					s.pop();
					now = arr[i][j] * 2;
					s.push(now);
					s.push(0);
				}
				else s.push(now);
			}
			stack<int> st;
			while (!s.empty()) {
				if (s.top() != 0)
					st.push(s.top());
				s.pop();
			}
			for (int j = N; j >= 1; j--) {
				if (!st.empty()) {
					arr_tmp[i][j] = st.top();
					st.pop();
				}
				else
					arr_tmp[i][j] = 0;
			}
		}
		if (check(arr, arr_tmp)) dfs(arr_tmp, cnt + 1);

		//down
		copy(&arr[0][0], &arr[20][21], &arr_tmp[0][0]);
		for (int i = 1; i <= N; i++) {
			stack<int> s;
			for (int j = N; j >= 1; j--) {
				int now = arr[j][i];
				if (now == 0) continue;
				if (!s.empty() && s.top() == now) {
					s.pop();
					now = arr[j][i] * 2;
					s.push(now);
					s.push(0);
				}
				else s.push(now);
			}
			stack<int> st;
			while (!s.empty()) {
				if (s.top() != 0)
					st.push(s.top());
				s.pop();
			}
			for (int j = N; j >= 1; j--) {
				if (!st.empty()) {
					arr_tmp[j][i] = st.top();
					st.pop();
				}
				else
					arr_tmp[j][i] = 0;
			}
		}
		if (check(arr, arr_tmp)) dfs(arr_tmp, cnt + 1);
	}
	
}
void run() {
	int arr[21][21];
	cin >> N;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
		cin >> arr[i][j];
	}
	dfs(arr,0);
	cout << mx;
}
int main() {
	run();
	return 0;
}