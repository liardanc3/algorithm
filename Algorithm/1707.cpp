#include <bits/stdc++.h>
using namespace std;
int V, E, tmp1, tmp2;
int arr[20001];
vector<int> vect[20001];
void bfs(vector<int> vect[]) {
	memset(arr, 0, sizeof(arr));
	int flag;
	
	for (int i = 1; i <= V; i++) {
		if (arr[i] == 0) {
			queue<int> q;
			q.push(i);
			flag = 1;
			arr[i] = flag;
			while (!q.empty()) {
				flag = -flag;
				int size = q.size();
				for (int i = 0; i < size; i++) {
					int now = q.front();
					q.pop();

					for (int j = 0; j < vect[now].size(); j++) {
						int next = vect[now].at(j);
						if (arr[next] != 0 && arr[next] != flag) {
							cout << "NO\n";
							return;
						}
						if (arr[next] == 0) {
							arr[next] = flag;
							q.push(next);
						}
					}
				}
			}
		}
	}
	cout << "YES\n";
	return;
}

int main() {
	int K; cin >> K;
	while (K--) {
		cin >> V >> E;
		for (int i = 1; i <= V; i++)
			vect[i].clear();
		for (int i = 1; i <= E; i++) {
			cin >> tmp1 >> tmp2;
			vect[tmp1].push_back(tmp2);
			vect[tmp2].push_back(tmp1);
		}
		bfs(vect);
	}

	return 0;
}