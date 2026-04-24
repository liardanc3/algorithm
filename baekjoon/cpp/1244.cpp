#include <bits/stdc++.h>
using namespace std;
int swit, bit[101]{ 0, }, n, gender, idx;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> swit;
    for (int i = 1; i <= swit; i++)
        cin >> bit[i];
    cin >> n;
    while (n--) {
        cin >> gender >> idx;
        if (gender == 1) {
            for (int i = idx; i <= swit; i += idx)
                bit[i] = !bit[i];
        }
        if (gender == 2) {
            bit[idx] = !bit[idx];
            for (int i = 1; 1 <= idx - i && idx + i <= swit; i++) {
                if (bit[idx + i] == bit[idx - i]) {
                    bit[idx + i] = !bit[idx + i];
                    bit[idx - i] = !bit[idx - i];
                }
                else break;
            }
        }
    }
    for (int i = 1; i <= swit; i++) {
        cout << bit[i];
        if (swit % 20 == 0)
            cout << '\n';
        else cout << ' ';
    }
        
    return 0;
}