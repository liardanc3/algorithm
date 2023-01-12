#include <bits/stdc++.h>
using namespace std;

int N, ret[10];
 
void f(int right, int depth) {
    [&]() {
        for (int i = 1; i <= min(9,right); i++) 
            ret[i] += depth;
    }();

    [&]() {
        while (right % 10 != 9 && 10 <= right) {
            string now = to_string(right);
            for (int i = 0; i < now.size(); i++)
                ret[now[i] - '0'] += depth;
            right--;
        }
    }();

    if (right < 10)
        return;

    [&]() {
        for (int i = 0; i <= 9; i++)
            ret[i] += depth * (right / 10);
    }();

    f(right / 10, depth * 10);
}

signed main() {
    cin >> N;
    f(N, 1);
    for (int i = 0; i <= 9; i++)
        cout << ret[i] << ' ';
    return 0;
}