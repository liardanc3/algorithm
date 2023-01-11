#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 배열로 변경

int binary_search(vector<int> element1, int element2) {
	int length = element1.size(); int half;
	int left = 0; int right = length-1; int check = 0;
	while (left<=right) {
		half = (left + right) / 2;
		if (element2 > element1.at(half))
			left = half+1;
		else if (element2 < element1.at(half))
			right = half-1;
		else {
			check = 1; break;
		}
	}
	return check;
}

int main() {
	int tmp;
	int num1; vector<int> element1;
	scanf("%d\n", &num1);
	for (int i = 0; i < num1; i++) {
		scanf("%d", &tmp);
		element1.push_back(tmp);
	}
	int num2; vector<int> element2;
	scanf("%d\n", &num2);
	for (int i = 0; i < num2; i++) {
		scanf("%d", &tmp);
		element2.push_back(tmp);
	}
	sort(element1.begin(), element1.end());
	
	for (int i = 0; i < num2; i++) {
		printf("%d\n", binary_search(element1, element2.at(i)));
	}

	return 0;
}