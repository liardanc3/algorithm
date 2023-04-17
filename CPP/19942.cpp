#include <bits/stdc++.h>
using namespace std;

struct food {
	int a, b, c, d, e;
	food(int aa, int bb, int cc, int dd, int ee) {
		a = aa, b = bb, c = cc, d = dd, e = ee;
	}
}; vector<food> vect;

vector<int> pick, ans;
int N, a, b, c, d, e, mina, minb, minc, mind, mn=1e9, nowa, nowb, nowc, nowd;
void dfs(int idx, int cost) {
	if (nowa >= mina && nowb >= minb && nowc >= minc && nowd >= mind && cost < mn) {
		mn = cost;
		ans.clear();
		for (int i : pick)
			ans.push_back(i);
	}
		
	if (idx == N)
		return;
	
	// idx번째 식재료 선택
	nowa += vect[idx].a;
	nowb += vect[idx].b;
	nowc += vect[idx].c;
	nowd += vect[idx].d;
	pick.push_back(idx);
	dfs(idx + 1, cost + vect[idx].e);
	nowa -= vect[idx].a;
	nowb -= vect[idx].b;
	nowc -= vect[idx].c;
	nowd -= vect[idx].d;
	pick.pop_back();

	// idx번째 식재료 선택하지 않음
	dfs(idx + 1, cost);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> mina >> minb >> minc >> mind;
	for(int i=0; i<N; i++) {
		cin >> a >> b >> c >> d >> e;
		vect.push_back({ a,b,c,d,e });
	}
	dfs(0, 0);
	if (mn == 1e9)
		cout << -1;
	else {
		cout << mn << '\n';
		for (int i : ans)
			cout << i << ' ';
	}
	return 0;
}