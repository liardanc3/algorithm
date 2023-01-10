#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, mx = 1;
bool cmp(const string& v1, const string& v2) {
	if (v1.size() != v2.size())
		return v1.size() < v2.size();
	return v1 < v2;
}
int main() {
	vector<string> vect;
	string tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end(), cmp);
	vect.erase(unique(vect.begin(), vect.end()), vect.end());
	for (int i = 0; i < vect.size()-1; i++) {
		string now = vect[i];
		for (int j = i + 1; j < vect.size(); j++) {
			string next = vect[j];
			if (next.substr(0, now.size()) == now) {
				vect.erase(vect.begin() + i);
				i--;
				break;
			}
		}
	}
	cout << vect.size();
	return 0;
}