#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dfs(int node,short check[],vector<short> vect[]) {
	if (check[node] == 1) return 0;
	check[node] = 1;
	cout << node << " ";
	for (int i = 0; i < vect[node].size(); i++) 
		dfs(vect[node].at(i),check,vect);
	return 0;
}

int bfs(int node, short check[], vector<short> vect[], queue<short> Q) {
	int tmp;
	if (check[node] == 1) return 0;
	check[node] = 1;
	cout << node << " ";
	for (int i = 0; i < vect[node].size(); i++) 
		Q.push(vect[node].at(i));
	while (!Q.empty()) {
		tmp = Q.front();
		Q.pop();
		if(check[tmp]!=1)
			bfs(tmp,check,vect,Q);
	}
	return 0;
}

int main() {
	short N, M, V;
	short tmp1, tmp2;
	queue<short> Q;
	cin >> N >> M >> V;
	vector<short> vect[1001];
	short *check;
	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		vect[tmp1].push_back(tmp2);
		vect[tmp2].push_back(tmp1);
	}
	for (int i = 1; i <= N; i++)
		sort(vect[i].begin(),vect[i].end());
	memset(check, 0, 1001);
	dfs(V, check, vect);
	cout << "\n";
	memset(check, 0, 1001);
	bfs(V, check, vect,Q);
	return 0; 
}