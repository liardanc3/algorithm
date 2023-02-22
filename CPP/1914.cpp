#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;

string ans = "1";
int N;
string sum(string a, string b) {
    int gap = max(a.length(), b.length()) - min(a.length(), b.length());
    if (a.length() < b.length())
        for (int i = 0; i < gap; i++) 
            a = "0" + a;
    else if (a.length() > b.length())
        for (int i = 0; i < gap; i++)
            b = "0" + b;
    vector<int> c;
    for (int i = 0; i < a.length(); i++) c.push_back(a[i] - '0' + b[i] - '0');
    reverse(c.begin(), c.end());
    for (int i = 0; i < c.size(); i++) {
        if (c[i] < 10) continue;
        if (i < c.size() - 1) c[i + 1] += c[i] / 10;
        else c.push_back(c[i] / 10);
        c[i] %= 10;
    }
    reverse(c.begin(), c.end());
    string ret;
    int i = 0; while (c[i] == 0) i++;
    if (i >= c.size()) ret.push_back('0');
    while (i < c.size()) {
        ret.push_back(char(c[i] + '0'));
        i++;
    }
    return ret;
}

void hanoi(int start, int tmp, int end, int h) {
	if (h == 1) {
		vect.push_back({ start,end });
		return;
	}
	
	hanoi(start, end, tmp, h - 1);
	vect.push_back({ start,end });
	hanoi(tmp, start, end, h - 1);
}
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
    for (int i = 0; i < N; i++) {
        ans = sum(ans, ans);
    }
    ans[ans.size() - 1]--;
    cout << ans << '\n';
	if (N <= 20) {
		hanoi(1, 2, 3, N);
		for (pii p : vect)
			cout << p.first << ' ' << p.second << '\n';
	}
		
	return 0;
}