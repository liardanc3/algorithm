#include <bits/stdc++.h>
using namespace std;

typedef pair<string, int> psi;

string str[]{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
int a, b;
vector<psi> vect;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		string now = to_string(i);
		string tostr = "";
		for (int i = 0; i < now.size(); i++)
			tostr += str[(now[i] - '0')] + ' ';
		vect.push_back({ tostr,i });
	}
	sort(vect.begin(), vect.end());
	for (int i = 1; i <= vect.size(); i++) {
		cout << vect[i-1].second << ' ';
		if (i % 10 == 0)
			cout << '\n';
	}
	return 0;
}
