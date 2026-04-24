#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> array;
	int max = -4000;
	int min = 4000;
	int tmp;
	int num; 
	int list[8001] = { 0, };
	int sum = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> tmp;
		sum += tmp;
		list[tmp + 4000]++;
		array.push_back(tmp);
		if (tmp > max)
			max = tmp;
		if (tmp < min)
			min = tmp;
	}
	
	double average = round(((double)sum / num));
	if (average == -0) average = 0;
	sort(array.begin() , array.end());
	int center = array.at(num / 2);

	int mmax = 0; int mmax_index = 0;
	int flag = 0;
	for (int i = 0; i <= 8000; i++) {
		if (list[i] > mmax) {
			mmax = list[i]; mmax_index = i; flag = 0;
		}
		if (mmax > 0 && list[i] == mmax) {
			flag++;
		}
	}
	if (flag != 0) {
		int check = 1;
		for (int i = 0; i <= 8000; i++) {
			if (list[i] == mmax) {
				if (check == 0) {
					mmax_index = i; break;
				}
				else check--;
			}
		}
	}
	printf("%d\n%d\n%d\n%d\n", (int)average, center, mmax_index-4000, max - min);
	return 0;
}