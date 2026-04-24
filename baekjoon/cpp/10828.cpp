#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> vect;
	int num, kill;
	cin >> num >> kill;
	for (int i = 0; i < num; i++) {
		vect.push_back(i + 1);
	}
	int index = kill-1;
	cout << "<";
	while (vect.size()!=0) {
		if (vect.size() == 1) {
			cout << vect.at(0);
			break;
		}
		cout << vect.at(index) << ", ";
		vect.erase(vect.begin() + index);
		index = (index + kill - 1) % vect.size();
		
	}
	cout << ">";
	return 0;
}