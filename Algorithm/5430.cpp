#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> vect;
	int T, range; string cmd, arr_S;
	char* arr = NULL, * tmp = NULL;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int err = 0;
		vect.clear();
		cin >> cmd >> range >> arr_S;
		vect.reserve(range);
		arr = const_cast<char*>(arr_S.c_str());
		tmp = strtok_r(arr, "[],", &arr);
		while (tmp != NULL) {
			vect.push_back(stoi(tmp));
			tmp = strtok_r(arr, "[],", &arr);
		}
		int Rstack = 0;
		int front = 0; int back = 0;
		for (int j = 0; j < cmd.size(); j++) {
			if (cmd[j] == 'R') {
				Rstack++;
			}
			else {
				if (Rstack % 2 == 1)
					back++;
				else
					front++;
			}
		}
		if (front + back > vect.size()) {
			cout << "error\n";
		}
		else {
			cout << "[";
			if (Rstack % 2 == 0) {
				for (int i = front; i < vect.size() - back; i++) {
					cout << vect.at(i);
					if (i != vect.size() - back - 1) cout << ",";
				}
			}
			else {
				for (int i = vect.size()-back-1; i >= front; i--) {
					cout << vect.at(i);
					if (i != front) cout << ",";
				}
			}
			cout << "]\n";
		}
	}
	return 0;
}