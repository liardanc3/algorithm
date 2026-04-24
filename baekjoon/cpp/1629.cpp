#include <bits/stdc++.h>
typedef long long ll;
ll a, b, c;
ll Q(ll b) {
	if (b==0) return 1;
	ll d = Q(b/2);
	if (b % 2> 0) return (a*((d*d)%c))%c;
	return (d*d)%c;
}
int main() {
	std::cin >> a >> b >> c;
	std::cout << Q(b);
}