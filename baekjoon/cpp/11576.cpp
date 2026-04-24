#include <bits/stdc++.h>
using namespace std;

int A, B, M, tmp, decimal;
vector<int> vect;
stack<int> st;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> A >> B >> M;
	while (M--) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	reverse(vect.begin(), vect.end());
	for (int i = 0; i < vect.size(); i++) {
		decimal += vect[i] * pow(A, i);
	}
	st.push(decimal % B);
	decimal -= decimal % B;
	while (decimal > 0) {
		if (decimal % B != 0) {
			st.push(decimal % B);
			decimal -= decimal % B;
		}
		else {
			decimal /= B;
			st.push(decimal % B);
			decimal -= decimal % B;
		}
	}
	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
	return 0;
}