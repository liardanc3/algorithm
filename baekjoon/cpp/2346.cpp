#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int N, tmp;
vector<pii> vect;
int main() {
	cin >> N;
	for(int i=1; i<=N; i++) {
		cin >> tmp;
		vect.push_back({ i,tmp });
	}
	int now = 0;
	while (1) {
		pii p = vect[now];
		cout << p.first << ' ';
		vect.erase(vect.begin() + now);
		if (vect.size() == 0)
			break;
		if (p.second > 0) 
			now = (now + p.second - 1) % vect.size();
		else {
			while (p.second != 0) {
				now--;
				p.second++;
				if (now == -1)
					now = vect.size() - 1;
			}
		}
	}
	return 0;
}