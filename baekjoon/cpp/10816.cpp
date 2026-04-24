#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	unordered_map<int, int> map;
	int num; cin >> num; int tmp;
	for (int i = 0; i < num; i++) {
		cin >> tmp;
		if (map.find(tmp) == map.end())
			map.insert(pair<int, int>(tmp, 1));
		else {
			map[tmp]++;
		}
	}
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> tmp; cout << map[tmp]; cout << " ";
	}
	return 0;
}