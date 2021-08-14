#include <iostream>
using namespace std;
int main() {
	int check_0[41] = { 0, };
	int check_1[41] = { 0, };
	check_0[0] = 1;
	check_1[1] = 1;
	int num; cin >> num;
	int tmp;
	for (int i = 2; i < 41; i++) {
		check_0[i] = check_0[i - 1] + check_0[i - 2];
		check_1[i] = check_1[i - 1] + check_1[i - 2];
	}
	for (int i = 0; i < num; i++) {
		cin >> tmp;
		cout << check_0[tmp] << " " << check_1[tmp] << "\n";
	}
	return 0;
}