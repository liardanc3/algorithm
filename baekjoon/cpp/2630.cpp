#include <iostream>
using namespace std;
int** paper, **check;
int white, blue;

void count_sqaure(int i, int j, int cnt) {
	if (check[i][j] != -1) paper[i][j] == 0 ? white++ : blue++;
	if (check[i][cnt - 1 + j] != -1) paper[i][cnt - 1 + j] == 0 ? white++ : blue++;
	if (check[cnt - 1 + i][j] != -1) paper[cnt - 1 + i][j] == 0 ? white++ : blue++;
	if (check[cnt - 1 + i][cnt - 1 + j] != -1) paper[cnt - 1 + i][cnt - 1 + j] == 0 ? white++ : blue++;
	check[i][j] = -1; check[i][cnt - 1 + j] = -1;
	check[cnt - 1 + i][j] = -1; check[cnt - 1 + i][cnt - 1 + j] = -1;
}

int check_square(int i, int j,int cnt) {
	int ret = -1;
	if (paper[i][j] == paper[i][cnt - 1 + j] && paper[i][cnt - 1 + j] == paper[cnt - 1 + i][j]
		&& paper[cnt - 1 + i][j] == paper[cnt - 1 + i][cnt - 1 + j]) {
		if (check[i][j] != -1 && check[i][cnt - 1 + j] != -1 && check[cnt - 1 + i][j] != -1 && check[cnt - 1 + i][cnt - 1 + j] != -1)
			ret = paper[i][j];
		else count_sqaure(i, j, cnt);
	}
	else count_sqaure(i, j, cnt);
	return ret;
}

int main() {
	white = 0; blue = 0;
	int num, tmp; cin >> num;
	paper = new int* [num];
	check = new int* [num];
	for (int i = 0; i < num; i++) {
		paper[i] = new int[num];
		check[i] = new int[num];
		for (int j = 0; j < num; j++) {
			cin >> tmp;
			paper[i][j] = tmp;
			check[i][j] = 0;
		}
	}
	for (int c = 2; c <= num; c *= 2)
		for (int i = 0; i < num; i += c)
			for (int j = 0; j < num; j += c) {
				tmp = check_square(i, j, c);
				if (tmp != -1 && c == num)
					paper[i][j] == 0 ? white++ : blue++;
	}
	cout << white << "\n" << blue;
	return 0;
}