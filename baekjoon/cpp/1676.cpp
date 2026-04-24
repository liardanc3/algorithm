#include <iostream>
#include <string>
using namespace std;

int main() {
	int num; cin >> num;
	int count = 0;
	for (int i = 1; i <= num; i++) {
		if (i % 125 == 0) {
			count +=3;
		}
		else if (i % 25 == 0) {
			count += 2;
		}
		else if (i % 5 == 0) {
			count++;
		}
	}
	cout << count;
	return 0;
}