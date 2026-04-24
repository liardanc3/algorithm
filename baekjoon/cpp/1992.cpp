#include <bits/stdc++.h>
using namespace std;
string result;
string divcon(int arr[][64], int N, int start_row, int start_col) {
	int check = arr[start_row][start_col];
	int same = 1;
	for (int i = start_row; i < N+start_row; i++) {
		for (int j = start_col; j < N+start_col; j++) {
			if (arr[i][j] != check) {
				same = 0;
				i = N + start_row; break;
			}
		}
	}
	if(same) result += to_string(check);
	if (!same) {
		result += "(";
		divcon(arr, N / 2, start_row, start_col);
		divcon(arr, N / 2, start_row, N / 2 + start_col);
		divcon(arr, N / 2, N / 2 + start_row, start_col);
		divcon(arr, N / 2, N / 2 + start_row, N / 2 + start_col);
		result += ")";
	}
	return result;
}

int main() {
	result = "";
	string tmp = "";
	int arr[64][64]{ 0, };
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for(int j=0; j<N; j++)
			arr[i][j] = tmp[j] - '0';
	}
	cout << divcon(arr, N,0,0);
	return 0;
}