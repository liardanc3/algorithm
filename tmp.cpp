#include <bits/stdc++.h>
using namespace std;
int N, M, K;
typedef pair<int, int> pii;
vector<int> vect[100001];
int ck[100001];
vector<pii> fr;
queue<int> QQQ;
int fun() {
	int cutcount = 0;
	while (!fr.empty()) {
		memset(ck, 0, sizeof(ck));
		int check = 1;
		int flag = 1;
		queue<int> q;
		q.push(1);
		ck[1] = 1;
		while (!q.empty()) {
			int size = q.size();

			flag = -flag;
			for (int j = 0; j < size; j++) {
				int now = q.front();
				q.pop();
				
				for (int i = 0; i < vect[now].size(); i++) {
					int next = vect[now].at(i);
					if (next == -1) continue;

					if (ck[next] == 0) {
						ck[next] = flag;
						q.push(next);
					}
					else if (ck[next] == flag)
						continue;
					else {
						check = 0;
						while (!q.empty())
							q.pop();
						j = size;
						break;
					}
				}
			}
		}
		if (check == 0) {
			if (QQQ.empty()) return -1;
			pii now = fr.at(QQQ.front()-1);
			QQQ.pop();
			for (int i = 0; i < vect[now.first].size(); i++) {
				if (vect[now.first].at(i) == now.second)
					vect[now.first].at(i) = -1;
			}
			cutcount++;
		}
		else {
			return cutcount;
		}
	}
	
}

int main() {
	cin >> N >> M >> K;
	int a, b;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		vect[a].push_back(b);
		fr.push_back(pii(a, b));
	}
	for (int i = 1; i <= K; i++) {
		cin >> a;
		QQQ.push(a);
	}
	int ans = fun();
	cout << ans;
	if (ans == -1) return 0;
	int a1=0, b1=0;
	for (int i = 1; i <= N; i++) {
		if (ck[i] == 1)
			a1++;
		else b1++;
	}
	if (a1 > b1) swap(a1, b1);
	cout << '\n' << a1 << ' ' << b1;
}