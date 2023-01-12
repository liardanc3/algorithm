#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	int count = 0;
	string name;
	cin >> N >> M;
	map<string,int> hash; 
	for (int i = 0; i < N; i++) {
		cin >> name;
		hash.insert(pair<string,int>(name, 0));
	}
	for (int i = 0; i < M; i++) {
		cin >> name;
		if (hash.find(name) != hash.end()) {
			hash[name]++;
			count++;
		}
	}
	cout << count << "\n";
	for (auto it = hash.begin(); it != hash.end(); it++) {
		if (it->second != 0)
			cout << it->first << "\n";
	}
	return 0;
}