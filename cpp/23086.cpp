#include <bits/stdc++.h>
using namespace std;
int n, m, k, u, v, r, ck[100001];
typedef pair<int, int> pii;
typedef tuple<bool, int, int> tii;
vector<int> uv_ban;
vector<pii> uv_vect;

tii bfs(int cut) {
	memset(ck, 0, sizeof(ck));
	vector<pii> uv_tmp = uv_vect;
	for (int i = 0; i < cut; i++) {
		uv_tmp[uv_ban[i]].first = -1;
		uv_tmp[uv_ban[i]].second = -1;
	}
	vector<int> vect[100001];
	for (int i = 0; i < m; i++) {
		int fst = uv_tmp[i].first;
		int snd = uv_tmp[i].second;
		if (fst > 0 && snd > 0) {
			vect[fst].push_back(snd);
			vect[snd].push_back(fst);
		}
	}
	queue<int> q;
	q.push(1);
	int flag = 1, R = 1, B = 0;
	ck[1] = flag;
	int count = 1;
	while (!q.empty()) {
		int size = q.size();
		flag = -flag;
		for (int i = 0; i < size; i++) {
			int now = q.front();
			q.pop();

			for (int j = 0; j < vect[now].size(); j++) {
				int next = vect[now][j];

				if (ck[next] == 0) {
					ck[next] = flag;
					if (flag == 1) R++;
					else B++;
					
					count++;
					q.push(next);
				}
				else if (ck[next] == -flag)
					return { false,0,0 };
			}
		}
	}
	if (count != n) return { false,0,0 };
	if (R > B) swap(R, B);
	return { true,R,B };
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		uv_vect.push_back({ u,v });
	}
	for (int i = 0; i < k; i++) {
		cin >> r;
		uv_ban.push_back(r - 1);
	}

	int left = 0, right = k, ans = -1, R = -1, B = -1;
	bool result;
	while (left <= right) {
		int mid = (left + right) / 2;
		tii ret = bfs(mid);
		result = get<0>(ret);

		if (result == false) {
			left = mid + 1;
		}
		else if (result == true) {
			right = mid - 1;
			ans = mid;
			R = get<1>(ret); B = get<2>(ret);
		}
	}
	if (ans == -1) cout << "-1";
	else {
		cout << ans << '\n';
		cout << R << ' ' << B;
	}

	return 0;
}