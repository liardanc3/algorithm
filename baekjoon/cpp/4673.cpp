#include <iostream>
using namespace std;

int main(void) {	
	int tmp;
	int array[10001] = { 0, };
	for (int i = 1; i <= 10000; i++ ) {
		if (i / 10 == 0)
			tmp = i * 2;
		// 1 + 1 = 2
		else if (i / 100 == 0)
			tmp = i + (i / 10) + (i % 10);
		// 36 + 3 + (36 - 3 * 10) = 36 + 3 + 6
		else if (i / 1000 == 0)
			tmp = i + (i / 100) + (i / 10)%10 + (i % 10);
		// 132 + 1 + (132 - 100)/10 + 132%10 = 132 + 1 + 3 + 2
		else
			tmp = i + (i / 1000) + ((i / 100) % 10) + (i / 10) % 10 + i % 10;
		// 1235 + 1 + 2 + 3 + 5
		if (tmp <= 10000)
			array[tmp] = 1;
	}
	for (int i = 1; i <= 10000; i++) {
		if (array[i] == 0)
			cout << i << endl;
	}
	return 0;
}