#include <iostream>	
#include <vector>
#include <string>
using namespace std;

typedef struct paper {
	int paper_num;
	int priority;
}paper;

int main() {
	int test_case_num;
	cin >> test_case_num;
	string answer = "";
	vector<paper> vect;
	vector<paper> ans_vect;
	int print_num, value, prio_tmp;
	for (int i = 0; i < test_case_num; i++) {
		cin >> print_num >> value;
		vect.clear();
		ans_vect.clear();
		int k = 0;
		for (int j = 0; j < print_num; j++) {	
			paper paper_tmp;
			cin >> prio_tmp;
			paper_tmp.paper_num = j;
			paper_tmp.priority = prio_tmp;
			vect.push_back(paper_tmp);
		}
	
		while (true) {
			if (vect.size() == 1) break;
			int index_check = 0;
			int high_pn = vect.front().paper_num;
			int high_p = vect.front().priority;
			for (int j = 0; j < print_num-k; j++) {
				if (vect.at(j).priority > high_p) {
					high_p = vect.at(j).priority;
					high_pn = vect.at(j).paper_num;
				}
			}
			
			for (; vect.front().paper_num != high_pn ;) {
				vect.push_back(vect.front());
				vect.erase(vect.begin());
			}
			
			ans_vect.push_back(vect.front());
			vect.erase(vect.begin());
			k++;
		}
		
		int find = 0;
		int ans = 1;
		vector<paper>::iterator it;
		for (it = ans_vect.begin(); it != ans_vect.end(); it++) {
			if ((*it).paper_num == value) {
				find = 1; break;
			}
			else {
				ans++;
			}
		}
		if (!find) {
			for (it = vect.begin(); it != vect.end(); it++) {
				if ((*it).paper_num == value) break;
				else {
					ans++;
				}
			}
		}
		answer = answer + to_string(ans) + '\n';
	}
	cout << answer;
	return 0;
}