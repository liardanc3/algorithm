#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> pdd;
typedef tuple<double, int, int> tii;
int n, mst[101];
vector<pdd> vect;
priority_queue<tii, vector<tii>, greater<tii>> pq;

int getRoot(int i) {
	return i == mst[i] ? i : mst[i] = getRoot(mst[i]);
}

double kruskal() {
	int m = 0;
	double sum = 0.0;
	while (m < n - 1) {

		double w = get<0>(pq.top());
		int a = get<1>(pq.top());
		int b = get<2>(pq.top()); 

		pq.pop();

		if (getRoot(a) == getRoot(b)) continue;

		mst[getRoot(a)] = getRoot(b);
		sum += w;
		m++;
	}
	return sum;
}


void init() {
	for (int i = 0; i <= 100; i++)
		mst[i] = i;
	cin >> n;
	double y, x, r;
	for (int i = 0; i < n; i++) {
		cin >> y >> x;
		vect.push_back(pdd(y, x));
	}
	for (int i = 0; i < vect.size()-1; i++) {
		for (int j = i + 1; j < vect.size(); j++) {
			y = pow(vect.at(i).first - vect.at(j).first, 2);
			x = pow(vect.at(i).second - vect.at(j).second, 2);
			r = sqrt(x + y);
			pq.push(tii(r, i, j));
		}
	}
}

int main() {
	init();
	cout << kruskal();
	return 0;
}