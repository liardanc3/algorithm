#include <iostream>
#include <map>
using namespace std;
int main() {
	int T, N, ans_p, ans_m ,tmp; string tmp1, tmp2;
	cin >> T;
	map<string, int> item;
	for (int i = 0; i < T; i++) {
		cin >> N;
		ans_p = 0; ans_m = 1;
		for (int j = 0; j < N; j++) {
			cin >> tmp1 >> tmp2;
			auto it = item.find(tmp2);
			if (it != item.end())
				it->second++;
			else item.insert(pair<string, int>(tmp2, 1));
		}
		for (auto it = item.begin(); it != item.end(); it++) {
			ans_m *= it->second + 1;
		}
		cout << ans_m -1 << "\n";
		item.clear();
	}
	return 0;
}