#include <bits/stdc++.h>
using namespace std;
int t, tmp;
vector<int> vect;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        for (int i = 0; i < 10; i++) {
            cin >> tmp;
            vect.push_back(tmp);
        }
        sort(vect.begin(), vect.end());

        cout << vect[7] << '\n';
        vect.clear();
    }
    return 0;
}