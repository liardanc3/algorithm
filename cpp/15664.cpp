#include <bits/stdc++.h>
using namespace std;

int N, M, tmp;
map<string, int> visited;
vector<int> vect;
void bt(int now, int len, string str) {
	if (len == M) {
		if (!visited[str]) {
			cout << str << '\n';
			visited[str] = 1;
		}
		return;
	}
	for (int i = now; i < vect.size(); i++) 
		bt(i + 1, len + 1, str + to_string(vect[i]) + ' ');
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	while (N--) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	bt(0, 0, "");
	return 0;
}