#include <bits/stdc++.h>
using namespace std;
int N, flag, cnt, prime[4000001];
vector<int> vect;
void init() {
	fill(&prime[0], &prime[4000001], 1);
	prime[0] = 0; prime[1] = 0;
	for (int i = 2; i <= 2000; i++) {
		if (prime[i] == 1) {
			for (int j = 2; i * j <= 4000000; j++)
				prime[j * i] = 0;
		}
	}
	for (int i = 2; i <= 4000000; i++) {
		if (prime[i] == 1)
			vect.push_back(i);
	}
}

int main() {
	cin >> N;
	init();
	int left = 0;
	int right = 0;
	while(vect.size()-1 >= right && vect[right]<=N && vect[left]<=N) {
		int sum = 0;
		for (int i = left; i <= right; i++)
			sum += vect.at(i);

		if (sum > N)
			left++;
		else if (sum < N)
			right++;
		else {
			cnt++;
			right++;
		}
	}
	cout << cnt;
	return 0;
}