#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<int> vect;
	vect.push_back(1);
	for (int i = 666; i <= 9999999; i++) {
		string tmp = to_string(i);
		for (int j = 0; j < tmp.size()-2; j++) {
			if (tmp[j] == '6' && tmp[j + 1] == '6' && tmp[j + 2] == '6') {
				vect.push_back(i);
				break;
			}
		}
	}
	int N; cin >> N;
	cout << vect[N];
	return 0;
}