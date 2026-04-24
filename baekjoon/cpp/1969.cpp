#include <bits/stdc++.h>
using namespace std;

int N, M, mn;
string tmp, ret;
vector<string> vect;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());

	for (int i = 0; i < M; i++) {
		int A = N, T = N, G = N, C = N;
		for (int j = 0; j < N; j++) {
			switch(vect[j][i]){
			case 'A':
				A--;
				break;
			case 'T':
				T--;
				break;
			case 'G':
				G--;
				break;
			case 'C':
				C--;
				break;
			}
		}
		int hd_min = min(min(A, T), min(G, C));
		if (A == hd_min)
			ret += 'A';
		else if (C == hd_min)
			ret += 'C';
		else if (G == hd_min)
			ret += 'G';
		else
			ret += 'T';
		mn += hd_min;
	}
	cout << ret << '\n' << mn;
	return 0;
}
