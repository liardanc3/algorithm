#include <bits/stdc++.h>
using namespace std;
int len[13]{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string a, b, c, d;
	int Month, DD, YY, HH, MM;
	cin >> a >> b >> c >> d;
	if (a == "January") Month = 1;
	if (a == "February") Month = 2;
	if (a == "March") Month = 3;
	if (a == "April") Month = 4;
	if (a == "May") Month = 5;
	if (a == "June") Month = 6;
	if (a == "July") Month = 7;
	if (a == "August") Month = 8;
	if (a == "September") Month = 9;
	if (a == "October") Month = 10;
	if (a == "November") Month = 11;
	if (a == "December") Month = 12;
	DD = stoi(b.substr(0, b.size() - 1));
	YY = stoi(c);
	HH = stoi(d.substr(0, 2));
	MM = stoi(d.substr(3, 2));
	int year, month, day, hour, min;
	if (YY % 400 == 0) len[2] = 29;
	if (YY % 4 == 0 && YY % 100 != 0) len[2] = 29;
	double mx = 60 * 24 * 365 * 1.f;
	if (len[2] == 29) mx += 60 * 24 * 1.f;
	double cnt = 0;
	for (year = YY, month = 1, day = 1, hour = 0, min = 0; ; min++) {
		if (min == 60) {
			hour++;
			min = 0;
			if (hour == 24) {
				day++;
				hour = 0;
				if (day > len[month]) {
					month++;
					day = 1;
				}
			}
		}
		if (month == Month && day == DD && hour == HH && min == MM)
			break;
		cnt++;
	}
	printf("%.12f",100*cnt/mx);
	return 0;
}