#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	string site_tmp, pass_tmp;
	map<string, string> MAP;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> site_tmp >> pass_tmp;
		MAP.insert(pair<string, string>(site_tmp, pass_tmp));
	}
	for (int i = 0; i < M; i++) {
		cin >> site_tmp;
		cout << MAP[site_tmp] << "\n";
	}
	return 0;
}