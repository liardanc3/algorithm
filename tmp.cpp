#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int, string> student;
int n, a, b, c;
string name;
vector<student> vect;
bool cmp(student& a, student& b) {
	if (get<0>(a) != get<0>(b))
		return get<0>(a) > get<0>(b);
	if (get<1>(a) != get<1>(b))
		return get<1>(a) < get<1>(b);
	if (get<2>(a) != get<2>(b))
		return get<2>(a) > get<2>(b);
	return get<3>(a) < get<3>(b);
}
int main() {
	cin >> n;
	while (n--) {
		cin >> name >> a >> b >> c;
		vect.push_back({ a,b,c,name });
	}
	sort(vect.begin(), vect.end(), cmp);
	for (student s : vect)
		cout << get<3>(s) << '\n';
	return 0;
}