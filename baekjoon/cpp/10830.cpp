#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> matrix;
ll N, B;
matrix mat;
matrix x(matrix a, matrix b) {
	matrix c;
	for (int i = 0; i < N; i++) {
		vector<int> vect_tmp;
		for (int j = 0; j < N; j++) {
			int tmp = 0;
			for (int k = 0; k < N; k++) {
				tmp +=
					(a.at(i).at(k) * b.at(k).at(j)) % 1000;
				tmp %= 1000;
			}
			vect_tmp.push_back(tmp);
		}
		c.push_back(vect_tmp);
	}
	return c;
}

matrix POW(matrix a, ll n){
	if (n == 1)
		return a;
	matrix hf = POW(a, n / 2);
	hf = x(hf, hf);
	if (n % 2 == 0)
		return hf;
	else return x(hf, a);
}

int main() {
	int tmp;
	vector<int> vect_tmp;
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			vect_tmp.push_back(tmp%1000);
		}
		mat.push_back(vect_tmp);
		vect_tmp.clear();
	}
	matrix ANS = POW(mat, B);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << ANS.at(i).at(j) << ' ';
		cout << '\n';
	}
	return 0;
}