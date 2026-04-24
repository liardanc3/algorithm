#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, mx=-1e16;

string tmp;

void dfs(string str, int idx) {
	if (idx == tmp.size()) {
		int now = 0;

		for (int i = 0; i < str.size()-1; i += 2) {
			char oper1 = str[i];

			int num = 0;
			if (str[i + 1] == '(') {
				int first = str[i + 2] - '0';
				char op = str[i + 3];
				int second = str[i + 4] - '0';

				if (op == '*')
					num = (first * second);
				else if (op == '+')
					num = first + second;
				else
					num = first - second;
				i += 4;
			}
			else
				num = str[i + 1] - '0';

			if (oper1 == '*') {
				if (i == 0)
					now = num;
				else now *= num;
			}
			else if (oper1 == '+')
				now += num;
			else
				now -= num;
		}
		//cout << now << " :: " << str << '\n';
		mx = max(mx, now);
		return;
	}

	// °ýÈ£ ¾øÀ½
	dfs(str + tmp[idx]+tmp[idx+1],idx + 2);

	// °ýÈ£ Ãß°¡
	if(idx+4<=tmp.size())
		dfs(str + "(" + tmp[idx] + tmp[idx + 1] + tmp[idx + 2] + ")" + tmp[idx+3], idx + 4);

	return;
}

signed main() {
	cin >> n >> tmp;
	tmp += "+";
	dfs("+", 0);
	cout << mx;
	return 0;
}