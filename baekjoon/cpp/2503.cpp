#include <bits/stdc++.h>
using namespace std;

typedef tuple<string, int, int> tsii;

int N, b, c, cnt, arr[10];
string a;
vector<tsii> vect;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> a >> b >> c;
		vect.push_back({ a,b,c });
	}
	for (int i = 1; i <= 9; i++) {
		arr[i] = 1;
		for (int j = 1; j <= 9; j++) {
			if (i == j) continue;
			arr[j] = 1;
			for (int k = 1; k <= 9; k++) {
				if (i == k || j == k) continue;
				arr[k] = 1;
				string now = "";
				now += (char)(i + '0');
				now += (char)(j + '0');
				now += (char)(k + '0');
				
				int flag = 1;
				for (int s = 0; s < vect.size() && flag; s++) {
					tsii t = vect[s];
					string ck = get<0>(t);
					int strike = get<1>(t);
					int ball = get<2>(t);

					int p1 = arr[ck[0] - '0'];
					int p2 = arr[ck[1] - '0'];
					int p3 = arr[ck[2] - '0'];

					int cond1 = (ck[0] - '0' == i);
					int cond2 = (ck[1] - '0' == j);
					int cond3 = (ck[2] - '0' == k);

					// 0 0
					if (strike == 0 && ball == 0) {
						if (arr[ck[0] - '0'] || arr[ck[1] - '0'] || arr[ck[2] - '0'])
							flag = 0;
					}
					// 0 1
					if (strike == 0 && ball == 1) {
						if (p1 + p2 + p3 != 1) 
							flag = 0;
						else {
							if (p1 && cond1)
								flag = 0;
							if (p2 && cond2)
								flag = 0;
							if (p3 && cond3)
								flag = 0;
						}
					}
					// 0 2
					if (strike == 0 && ball == 2) {
						if (p1 + p2 + p3 != 2)
							flag = 0;
						else {
							if (p1 && cond1)
								flag = 0;
							if (p2 && cond2)
								flag = 0;
							if (p3 && cond3)
								flag = 0;
						}
					}
					// 0 3
					if (strike == 0 && ball == 3) {
						if (p1 + p2 + p3 != 3)
							flag = 0;
						else {
							if (p1 && cond1)
								flag = 0;
							if (p2 && cond2)
								flag = 0;
							if (p3 && cond3)
								flag = 0;
						}
					}
					// 1 0
					if (strike == 1 && ball == 0) {
						if (p1 + p2 + p3 != 1)
							flag = 0;
						else {
							if (p1 && !cond1)
								flag = 0;
							if (p2 && !cond2)
								flag = 0;
							if (p3 && !cond3)
								flag = 0;
						}
					}
					// 1 1
					if (strike == 1 && ball == 1) {
						if (p1 + p2 + p3 != 2)
							flag = 0;
						else {
							if (p1 && p2) {	
								if (cond1 + cond2 != 1)
									flag = 0;
							}
							if (p1 && p3) {
								if (cond1 + cond3 != 1)
									flag = 0;
							}
							if (p2 && p3) {
								if (cond2 + cond3 != 1)
									flag = 0;
							}
						}
					}
					// 1 2
					if (strike == 1 && ball == 2) {
						if (p1 + p2 + p3 != 3)
							flag = 0;
						else {
							if (cond1 + cond2 + cond3 != 1)
								flag = 0;
						}
					}
					// 2 0
					if (strike == 2 && ball == 0) {
						if (p1 + p2 + p3 != 2)
							flag = 0;
						else {
							if (p1 && p2) {
								if (cond1 + cond2 != 2)
									flag = 0;
							}
							if (p1 && p3) {
								if (cond1 + cond3 != 2)
									flag = 0;
							}
							if (p2 && p3) {
								if (cond2 + cond3 != 2)
									flag = 0;
							}
						}
					}
					// 2 1
					if (strike == 2 && ball == 1) {
						if (p1 + p2 + p3 != 3)
							flag = 0;
						else {
							if (cond1 + cond2 + cond3 != 2)
								flag = 0;
						}
					}
				}
				if (flag) {
					cnt++;
					//cout << now << '\n';
				}
				arr[k] = 0;
			}
			arr[j] = 0;
		}
		arr[i] = 0;
	}
	cout << cnt;
	return 0;
}