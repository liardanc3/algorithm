#include <bits/stdc++.h>
using namespace std;
int len[13]{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int sy, sm, sd, fy, fm, fd, dcnt = 0;
int main() {
	cin >> sy >> sm >> sd >> fy >> fm >> fd;
	int year, month, day;
	if (sy + 1000 <= fy && (sm < fm || (sm == fm && sd <= fd))) {
		cout << "gg";
		return 0;
	}
	for (year = sy, month = sm, day = sd; !(year == sy + 1000 && month == sm && day == sd); day++) {
		
		// 윤년 체크
		bool flag = false;
		if (year % 4 == 0) flag = true;
		if (year % 100 == 0) flag = false;
		if (year % 400 == 0) flag = true;
		if (flag) len[2] = 29;
		else len[2] = 28;

		// 날짜 증가 조절
 		if (day > len[month]) {
			day = 1;
			month++;
			if (month > 12) {
				year++;
				month = 1;
			}
		}

		// 캠프 체크
		if (year == fy && month == fm && day == fd) {
			cout << "D-" << dcnt;
			return 0;
		}

		dcnt++;
	}
	cout << "gg";

	return 0;
}