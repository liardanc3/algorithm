#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a, b, p, q, visited[11]{ 0, }, arr[11]{ 0, };
vector<ll> vect[11];
void updateTree(ll a, ll a_piv) {
	queue<ll> q;
	for (ll i = 0; i < vect[a].size(); i++) {
		visited[vect[a][i]] = 1;
		q.push(vect[a][i]);
	}

	while (!q.empty()) {
		ll now = q.front(); q.pop();
		arr[now] *= a_piv;

		for (ll i = 0; i < vect[now].size(); i++) {
			ll next = vect[now][i];
			if (!visited[next]) {
				visited[next] = 1;
				q.push(next);
			}
		}
	}
}
int main() {
	cin >> n;
	for (ll i = 1; i < n; i++) {
		memset(visited, 0, sizeof(visited));
		cin >> a >> b >> p >> q;
		if (vect[a].size() == 0 && vect[b].size() == 0) {
			vect[a].push_back(b);
			vect[b].push_back(a);
			arr[a] = p, arr[b] = q;
		}
		else {
			if (vect[a].size() != 0 && vect[b].size() == 0) {
				ll a_piv = p;
				ll b_piv = arr[a];

				arr[a] = a_piv * b_piv;
				visited[a] = 1;
				updateTree(a, a_piv);
				arr[b] = q * b_piv;

			}
			else if (vect[a].size() == 0 && vect[b].size() != 0) {
				ll a_piv = arr[b];
				ll b_piv = q;

				arr[b] = a_piv * b_piv;
				visited[b] = 1;
				updateTree(b, b_piv);
				arr[a] = p * a_piv;
			}

			else {
				ll a_piv = arr[b];
				ll b_piv = arr[a];

				arr[a] *= a_piv * p;
				arr[b] *= b_piv * q;
				visited[a] = 1;
				visited[b] = 1;

				updateTree(a, a_piv * p);
				updateTree(b, b_piv * q);
			}
			vect[a].push_back(b);
			vect[b].push_back(a);
		}
	}
	ll mn = 914748300000000000;
	for (int i = 0; i < n; i++)
		mn = min(mn, arr[i]);

	vector<ll> prime;
	prime.push_back(2), prime.push_back(3);
	for (ll i = 5; i <= (int)(sqrt(mn)); i++) {
		bool flag = true;
		for (ll j = 0; prime[j] * prime[j] <= i; j++) {
			if (i % prime[j] == 0) {
				flag = false;
				break;
			}
		}
		if (flag)
			prime.push_back(i);
	}

	ll div = 1;
	for (ll i = 0; i < prime.size() && prime[i] <= mn; i++) {
		bool flag = true;
		for (ll j = 0; j < n; j++) {
			if ((arr[j] / div) % prime[i] != 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			div *= prime[i];
			mn /= prime[i];
			i = -1;
		}
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] / div << ' ';

	return 0;
}