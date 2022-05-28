#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<int> vect;
vector<pii> _list;
int n, sum;
int main() {
    for (int i = 1; i <= 8; i++) {
        cin >> n;
        _list.push_back({ n,i });
    }
    sort(_list.rbegin(), _list.rend());
    for (int i = 0; i < 5; i++) {
        sum += _list[i].first;
        vect.push_back(_list[i].second);
    }
    sort(vect.begin(), vect.end());
    cout << sum << '\n';
    for (int i = 0; i < 5; i++)
        cout << vect[i] << ' ';
    return 0;
}