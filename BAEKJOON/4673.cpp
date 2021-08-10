#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int max = -4000;
	int min = 4000;
	int num; int array[500000] = { 0, };
	int list[8001] = { 0, };
	float sum = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &array[i]);
		sum += array[i];
		list[array[i] + 4000]++;

		if (array[i] > max)
			max = array[i];
		else if (array[i] < min)
			min = array[i];
	}

	int average;
	average = round((double)(sum / num));
	sort(array, array + num);
	int center = array[num / 2];

	int mmax = -1; int count = 0; int value = 0;
	for (int i = 0; i <= 8000; i++) {
		if (list[i] > mmax) {
			count = 0;
			mmax = list[i];
			value = i - 4000;
		}
		else if (list[i] == mmax) {
			count++;
			mmax = list[i];
			value = i - 4000;
		}
	}
	int check = 2;
	if (count != 0) {
		for (int i = 0; i <= 8000; i++) {
			if (list[i] == mmax) {
				check -= 1;
				if (check == 0) {
					value = i - 4000;
					break;
				}
			}
		}
	}
	printf("%d\n%d\n%d\n%d", average, center, value, max - min);
	return 0;
}