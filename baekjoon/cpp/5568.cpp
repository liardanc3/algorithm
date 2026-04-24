#include <bits/stdc++.h>
using namespace std;

string tmp;
int N, K, visited[10];
vector<string> vect;
set<string> s;

void f(int len, string now) {
	if (len == K) {
		s.insert(now);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			f(len + 1, now + vect[i]);
			visited[i] = 0;
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	for(int i=0; i<N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	f(0, "");
	cout << s.size();
	return 0;
}
