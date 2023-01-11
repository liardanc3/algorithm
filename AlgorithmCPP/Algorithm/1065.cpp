#include <iostream>
using namespace std;

int main(void) {
	int N; cin >> N;
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (i / 100 == 0)
			sum++;
		else if (i != 1000)
			if (i / 100 - (i / 10) % 10 == (i / 10) % 10 - i % 10)
				sum++;
	}
	cout << sum;
	return 0;
}