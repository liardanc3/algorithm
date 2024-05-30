#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<pii> vect;
int n, x, y;
double mx = 0;
void solve(int i, int j, int k) {
    vector<pii> tmp;
    tmp.push_back(vect[i]), tmp.push_back(vect[j]), tmp.push_back(vect[k]);
    sort(tmp.begin(), tmp.end());

    double x1 = tmp[0].first;
    double y1 = tmp[0].second;
    double x2 = tmp[1].first;
    double y2 = tmp[1].second;
    double x3 = tmp[2].first;
    double y3 = tmp[2].second;

    double dx1 = x2 - x1;
    double dy1 = y2 - y1;
    double dx2 = x3 - x1;
    double dy2 = y3 - y1;
    double ax1 = abs(dx1);
    double ay1 = abs(dy1);
    double ax2 = abs(dx2);
    double ay2 = abs(dy2);

    /*double slope1 = dy1 / (ax1 + ay1);
    double slope2 = dy2 / (ax2 + ay2);
    if (slope1 == slope2) return;*/

    double a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double b = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    double c = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    double s = (a + b + c) / 2;
    double S = sqrt(s * (s - a) * (s - b) * (s - c));
    mx = max(mx, S);
}

int main() {
    cin >> n;
    int sz = n;
    while (n--) {
        cin >> x >> y;
        vect.push_back({ x,y });
    }
    for (int i = 0; i < sz - 2; i++) {
        for (int j = i + 1; j < sz - 1; j++) {
            for (int k = j + 1; k < sz; k++)
                solve(i, j, k);
        }
    }
    cout << fixed;
    cout.precision(10);
    cout << mx;
}