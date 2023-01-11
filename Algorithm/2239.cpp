#include <bits/stdc++.h>
using namespace std;
int arr[10][10];
typedef pair<int, int> pii;
vector<pii> vect;
bool possible(int y, int x, int number) {
	for (int i = 1; i <= 9; i++) {
		if (arr[i][x] == number || arr[y][i] == number)
			return false;
	}
	int y_start = 3 * ((y - 1) / 3) + 1;
	int x_start = 3 * ((x - 1) / 3) + 1;
	for (int i = y_start; i <= y_start + 2; i++) {
		for (int j = x_start; j <= x_start + 2; j++) {
			if (arr[i][j] == number)
				return false;
		}
	}
	return true;
}
bool dfs(int idx) {
	if (idx == vect.size()) return true;
	int y = vect[idx].first;
	int x = vect[idx].second;
	bool result;
	for (int j = 1; j <= 9; j++) {
		if (possible(y, x, j)) {
			arr[y][x] = j;
			result = dfs(idx + 1);
			if (!result)
				arr[y][x] = 0;
		}
		
	}
	return arr[y][x] != 0 ? true : false;
}
void init() {
	string tmp;
	for (int i = 1; i <= 9; i++) {
		cin >> tmp;
		for (int j = 1; j <= 9; j++) {
			arr[i][j] = tmp.at(j - 1) - '0';
			if (arr[i][j] == 0)
				vect.push_back({ i,j });
		}
	}
}
int main() {
	init();
	dfs(0);
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++)
			cout << arr[i][j];
		cout << '\n';
	}
	return 0;
}