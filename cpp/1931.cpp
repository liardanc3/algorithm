#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin >> T;
	int tmp1, tmp2;
	int max = 0;
	int sum = 0;
	map<int, int> M;
	vector<int> vect;
	for (int i = 0; i < T; i++) {
		cin >> tmp1 >> tmp2;
		if (tmp1 == tmp2) {
			sum++; vect.push_back(tmp1); continue;
		}
		if(M.find(tmp1) == M.end())
			M.insert(pair<int,int>(tmp1,tmp2));
		else {
			if (M.find(tmp1)->second > tmp2) {
				M.erase(tmp1);
				M.insert(pair<int, int>(tmp1, tmp2));
			}
		}
		tmp1 > max ? max = tmp1 : 1;
	}
	if (!M.empty()) {
		int start = M.begin()->first;
		while (start <= max) {
			while (M.find(start) == M.end()) start++;
			for (int i = start; i < M[start]; i++) {
				if (M.find(i) != M.end() && M[i] < M[start]) {
					start = i; continue;
				}
			}
			sum++;
			int cnt = 0;
			int max_tmp = 0;
			for (auto it = vect.begin(); it != vect.end(); it++) {
				if (*it < M[start] && *it > start) {
					cnt++; max_tmp = *it;
				}
			}
			if (cnt > 0) {
				sum--;
				start = max_tmp;
			}
			else start = M[start];
		}
	}
	cout << sum;
	return 0;
}