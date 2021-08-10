#include <iostream>	
#include <string>
#include <vector>
using namespace std;

int main() {
	int num, card, ans, tmp;
	cin >> num;
	string answer = "";
	for (int i = 0; i < num; i++) {
		cin >> card >> ans;
		int value = 1;
		vector<int> deq;
		for (int j = 0; j < card; j++) {
			cin >> tmp; deq.push_back(tmp);
		}
		int counting = 0; 
		int max = deq.front();
		for (int j = 0; j < card; j++) {
			if (deq.at(j) > max) {
				max = deq.at(j);
				counting=1;
			}
			if (deq.at(j) == max)
				counting++;
		}

		answer += to_string(value) + '\n';
	}
	cout << answer;
	return 0;
}