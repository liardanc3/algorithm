#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int N, M, B,tmp;
	cin >> N >> M >> B;
	int ans = 0;
	int sum;
	int min = 256; int max = 0;
	
	int** ground = new int*[N];
	for (int i = 0; i < N; i++)
		ground[i] = new int[M];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			tmp > max ? max = tmp : (tmp < min) ? min = tmp : 1;
			ground[i][j] = tmp;
			
		}
	}
	if (N == 1 && M == 1) {
		cout << "0 " << tmp;
		return 0;
	}
	multimap<int,int> answerList;
	for (int k = min; k <= max; k++) {
		tmp = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (ground[i][j] < k)
					tmp += (k - ground[i][j]);
				if (ground[i][j] > k)
					tmp += 2 * (ground[i][j] - k);
			}
		}
		answerList.insert(pair<int,int>(tmp,k));
	}

	int needB; int check = 0; int ttmp;
	multimap<int, int>::iterator it;
	for (it = answerList.begin(); it != answerList.end(); it++) {
		if (check == 1 && it->first != sum) break;
		tmp = it->second; needB = B;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (ground[i][j] < tmp) {
					needB-=tmp-ground[i][j];
				}
				if (ground[i][j] > tmp)
					needB+=ground[i][j]-tmp;
			}
		}
		if (needB < 0 && check == 1) {
			tmp = ttmp;
		}
		if (needB >= 0) {
			if (check == 1 && ans > tmp) continue;
			ans = tmp;  sum = it->first; 
			check = 1; ttmp = ans;
		}
	}
	
	cout << sum << " " << ans;
	return 0;
}