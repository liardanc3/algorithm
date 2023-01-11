#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, tmp;
vector<int> vect;
void iqtest(int a, int b) {
	for (int i = 0; i < N - 1; i++) {
		if (vect[i] * a + b != vect[i + 1]) {
			cout << "B";
			return;
		}
	}
	cout << vect[N - 1] * a + b;
	//cout << "\nx = " << a << " y = " << b;
}
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	if (vect.size() == 1)
		cout << "A";
	else if (vect.size() == 2) {
		if (vect[0] == vect[1])
			cout << vect[0];
		else
			cout << "A";
	}
	else {
		int a = vect[0];
		int b = vect[1];
		int c = vect[2];
		if (b - a == 0 && c - b == 0) {
			iqtest(1, 0);
			return 0;
		}
		// b=ax+y
		// c=x(ax+y)+y;
		// ax^2+xy+y-c = 0
		// y = b-ax;
		// ax^2+x(b-ax)+(b-ax)-c=0
		// bx-ax+b-c=0
		// (b-a)x+b-c=0
		// x=(c-b)/(b-a)
		if (b - a == 0 || ((c-b)!=0 && abs(c-b)<abs(b-a))) 
			cout << "B";
		else {
			int x = (c - b) / (b - a);
			int y = b - a * x;
			iqtest(x, y);
		}
	}
	return 0;
}