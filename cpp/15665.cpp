#include <bits/stdc++.h>
using namespace std;

int N, tmp, M;
vector<int> vect;
map<string, int> visited;
void bt(int len, string str) {
	if (len == M) {
		if (!visited[str]) {
			cout << str << '\n';
			visited[str] = 1;
		}
		return;
	}
	for (int i = 0; i < N; i++) 
		bt(len + 1, str + to_string(vect[i]) + ' ');
	return;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	bt(0, "");
	return 0;
}