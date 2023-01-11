#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;	cin >> T;
	while(T--) {
		int M, N, X, Y, ans = -1;
		cin >> M >> N >> X >> Y;
		if(X > Y)  { swap(X, Y); swap(M, N); }
		for (int i = 0; i < N && ans==-1; i++) 
			(M * i) % N == Y - X ? ans = i : 0;
		ans == -1 ? printf("-1\n") : printf("%d\n",ans*M+X);
	}
}