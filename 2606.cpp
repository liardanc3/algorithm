#include <iostream>
#include <vector>
using namespace std;
int check[101];
vector<int> network[101];
void dfs(int start) {
	if (check[start] == 0)
		check[start] = 1;
	for (int i = 0; i < network[start].size(); i++) {
		if(check[network[start].at(i)]==0)
			dfs(network[start].at(i));
	}
	
}
int main() {
	int com, link, tmp1, tmp2;
	cin >> com >> link;
	for (int i = 1; i <=link; i++) {
		cin >> tmp1 >> tmp2;
		network[tmp1].push_back(tmp2);
		network[tmp2].push_back(tmp1);
	}
	dfs(1); int count = 0;
	for (int i = 2; i <= com; i++) {
		if (check[i] == 1)
			count++;
	}
	cout << count;
	return 0;
}