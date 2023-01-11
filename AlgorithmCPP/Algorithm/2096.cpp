#include <bits/stdc++.h>
using namespace std;
int arr[100000][3], N, d[2][3];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= 2; j++)
			cin >> arr[i][j];
	}
	
	copy(&arr[0][0], &arr[0][3], &d[0][0]);
	for (int i = 1; i < N; i++) {
		
		d[1][0] = max(d[0][0] + arr[i][0], d[0][1] + arr[i][0]);
		d[1][1] = max(d[0][0] + arr[i][1], max(d[0][1] + arr[i][1], d[0][2] + arr[i][1]));
		d[1][2] = max(d[0][1] + arr[i][2], d[0][2] + arr[i][2]);
		
		copy(&d[1][0], &d[1][3], &d[0][0]);
	} 
	cout << *max_element(&d[0][0], &d[0][3]) << ' ';
	
	memset(d, 0, sizeof(d));
	copy(&arr[0][0], &arr[0][3], &d[0][0]);
	for (int i = 1; i < N; i++) {
		
		d[1][0] = min(d[0][0] + arr[i][0], d[0][1] + arr[i][0]);
		d[1][1] = min(d[0][0] + arr[i][1], min(d[0][1] + arr[i][1], d[0][2] + arr[i][1]));
		d[1][2] = min(d[0][1] + arr[i][2], d[0][2] + arr[i][2]);
		
		copy(&d[1][0], &d[1][3], &d[0][0]);
	} 
	cout << *min_element(&d[0][0], &d[0][3]);
	return 0;
}