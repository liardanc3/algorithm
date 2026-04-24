#include <bits/stdc++.h>
using namespace std;
vector<int> vect;
int arr[7]{ 0, }, tmp;
int visited[9]{ 0, };
void bt(int start, int now) {
	if (now == 7) {
		int sum = 0;
		for (int i = 0; i < now; i++) 
			sum += arr[i];
		if (sum == 100) {
			for (int i = 0; i < 7; i++)
				cout << arr[i] << '\n';
			exit(0);
		}
		return;
	}
	for (int i = start; i < 9; i++) {
		if (visited[i] == 0) {
			arr[now++] = vect[i];
			visited[i] = 1;
			bt(start + 1, now);
			now--;
			visited[i] = 0;
		}
	}
	return;
}

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());
	bt(0, 0);
}