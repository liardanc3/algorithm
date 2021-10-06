#include <bits/stdc++.h>
using namespace std;
long long t, n, m, tmp;
vector<int> nowA, nowB;
map<int, long long> mapA, mapB;
vector<int> num;
int main() {
	cin >> t;
	cin >> n;
	nowA.push_back(-1);
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		nowA.push_back(tmp);
	}
	cin >> m;
	nowB.push_back(-1);
	for (int i = 1; i <= m; i++) {
		cin >> tmp;
		nowB.push_back(tmp);
	}
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = i; j <= n; j++) {
			sum += nowA.at(j);
			if (mapA.find(sum) == mapA.end())
				mapA.insert(pair<int, int>(sum, 1));
			else
				mapA[sum]++;
			num.push_back(sum);
		}
	}
	for (int i = 1; i <= m; i++) {
		int sum = 0;
		for (int j = i; j <= m; j++) {
			sum += nowB.at(j);
			if (mapB.find(sum) == mapB.end())
				mapB.insert(pair<int, int>(sum, 1));
			else
				mapB[sum]++;
			num.push_back(sum);
		}
	}
	long long ret = 0;
	
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	for (int i = 0; i < num.size(); i++) {
		int now = num[i];
		if(mapA.find(now)!=mapA.end() && mapB.find(t-now)!=mapB.end())
			ret += mapA[now] * mapB[t - now];
	}
	cout << ret;
	return 0;
}