#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unordered_map<int, string> dogam_num;
	unordered_map<string, int> dogam_name;
	int num, solve,tmp;
	string poket;
	cin >> num >> solve;
	for (int i = 1; i <= num; i++) {
		cin >> poket;
		dogam_num.insert(pair<int, string>(i, poket));
		dogam_name.insert(pair<string, int>(poket, i));
	}
	for (int i = 0; i < solve; i++) {
		cin >> poket;
		int digit = 1;
		for (char c : poket) {
			if (isdigit(c) == 0) {
				digit = 0; break;
			}
		}
		if (digit) {
			digit = stoi(poket);
			cout << dogam_num[digit] << "\n";
		}
		else {
			cout << dogam_name[poket] << "\n";
		}
	}
	return 0;
}