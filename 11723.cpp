#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unsigned int cmd = 0;
	string command = "";

	int num;
	unsigned int target;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> command;
		target = -1;
		if (command.compare("empty") == 0) {
			cmd &= 0;
		}
		else if (command.compare("all") == 0) {
			cmd = 1048575;
		}
		else if (command.compare("add") == 0) {
			cin >> target;
			cmd |= (1 << (target - 1));
		}
		else if (command.compare("remove") == 0) {
			cin >> target;
			cmd &= (1048575 ^ (1 << (target - 1)));
		}
		else if (command.compare("toggle") == 0) {
			cin >> target;
			cmd ^= 1<<(target-1);
		}
		else {
			cin >> target;
			cout << ((cmd >> (target - 1)) & 1) << '\n';
		}
	}
	return 0;
}