#include <bits/stdc++.h>
using namespace std;
queue<int> Q;
int arr[101], ck[101];

int bfs(vector<int> vect[]) {
	int cnt = -1;
	while (!Q.empty()) {
		cnt++;
		int size = Q.size();
		for (int i = 0; i < size; i++) {
			int tmp = Q.front(); Q.pop();
			ck[tmp] = 1;
			if (tmp == 100) return cnt;
			if (tmp != 100) {
				for (int j = 0; j < vect[tmp].size(); j++) {
					if(ck[vect[tmp].at(j)]!=1)
						Q.push(vect[tmp].at(j));
				}
			}
		}
	}
	return cnt;
}

void init(vector<int> vect[]) {
	for (int i = 1; i < 100; i++) {
		if (arr[i] != 0) {
			for (int j = arr[i]+1; j < arr[i] + 7 && j <= 100; j++) {
				if (arr[j] != 0)
					vect[i].push_back(arr[j]);
				else vect[i].push_back(j);
			}
		}
		else {
			for (int j = i + 1; j < i + 7 && j <= 100; j++) {
				if (arr[j] != 0)
					vect[i].push_back(arr[j]);
				else vect[i].push_back(j);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(arr, 0, sizeof(arr));
	vector<int> vect[101];
	int N, M, tmp1, tmp2; cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		cin >> tmp1 >> tmp2;
		arr[tmp1] = tmp2;
	} init(vect);
	Q.push(1);
	cout << bfs(vect);
	return 0;
}