#include <bits/stdc++.h>
using namespace std;
int arr[130]{ 0, };
int main() {
	string tmp; cin >> tmp;
	bool flag = true;
	for (int i = 0; i < tmp.size() - 1; i++) {
		if (tmp[i] != tmp[i + 1]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << tmp;
		return 0;
	}

	int origin = tmp.size() % 2;
	for (int i = 0; i < tmp.size(); i++)
		arr[tmp[i]]++;
	int odd = 0, even = 0;
	for (int i = 65; i <= 90; i++) {
		if (arr[i] % 2)
			odd++;
		else even++;
	}

	if (origin == 0 && odd > 0) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}
	if (origin == 1 && odd > 1) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	if (origin == 0) {
		string now = "";
		for (int i = 65; i <= 90; i++) {
			int len = arr[i] / 2;
			for (int j = 0; j < len; j++) {
				now += (char)i;
			}
		}
		cout << now;
		reverse(now.begin(), now.end());
		cout << now;
		return 0;
	}
	#include <bits/stdc++.h>
using namespace std;
int arr[130]{ 0, };
int main() {
	string tmp; cin >> tmp;
	bool flag = true;
	for (int i = 0; i < tmp.size() - 1; i++) {
		if (tmp[i] != tmp[i + 1]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << tmp;
		return 0;
	}

	int origin = tmp.size() % 2;
	for (int i = 0; i < tmp.size(); i++)
		arr[tmp[i]]++;
	int odd = 0, even = 0;
	for (int i = 65; i <= 90; i++) {
		if (arr[i] % 2)
			odd++;
		else even++;
	}

	if (origin == 0 && odd > 0) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}
	if (origin == 1 && odd > 1) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	if (origin == 0) {
		string now = "";
		for (int i = 65; i <= 90; i++) {
			int len = arr[i] / 2;
			for (int j = 0; j < len; j++) {
				now += (char)i;
			}
		}
		cout << now;
		reverse(now.begin(), now.end());
		cout << now;
		return 0;
	}

	if (origin == 1) {
		string now = "";
		char last;
		for (int i = 65; i <= 90; i++) {
			int len = arr[i];
			if (len % 2) {
				last = (char)i;
				len--;
			}
			for (int j = 0; j < len / 2; j++)
				now += (char)i;
		}
		cout << now;
		cout << last;
		reverse(now.begin(), now.end());
		cout << now;
	}
	return 0;
}
	if (origin == 1) {
		string now = "";
		char last;
		for (int i = 65; i <= 90; i++) {
			int len = arr[i];
			if (len % 2) {
				last = (char)i;
				len--;
			}
			for (int j = 0; j < len / 2; j++)
				now += (char)i;
		}
		cout << now;
		cout << last;
		reverse(now.begin(), now.end());
		cout << now;
	}
	return 0;
}