#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, M, R, tmp, tmp1, tmp2, hn, ans, root;
int tree[51];
vector<int> party[51];

int getRoot(int i) {
    if (tree[i] != i)
        tree[i] = getRoot(tree[i]);
    return tree[i];
}
int main() {
    cin >> N >> M >> R;
    for (int i = 1; i <= N; i++)
        tree[i] = i;
    root = 0;
    for (int i = 0; i < R; i++) {
        cin >> tmp;
        if (i == 0)
            root = tmp;
        else tree[tmp] = root;
    }
    for (int i = 1; i <= M; i++) {
        cin >> hn;
        if (hn >= 1) {
            cin >> tmp1;
            party[i].push_back(tmp1);
            for (int j = 0; j < hn - 1; j++) {
                cin >> tmp2;
                party[i].push_back(tmp2);
                if (getRoot(tmp2) == root)
                    tree[getRoot(tmp1)] = root;
                else
                    tree[getRoot(tmp2)] = getRoot(tmp1);
            }
        }
    }


    ans = M;
    for (int i = 1; i <= M; i++) {
        int ck = 1;
        for (int j = 0; j < party[i].size(); j++) {
            if (getRoot(party[i].at(j)) == root) {
                ck = 0;
                break;
            }
        }
        if (ck == 0) ans--;
    }
    cout << ans;
    return 0;
}