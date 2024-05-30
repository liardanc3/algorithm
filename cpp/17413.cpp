#include <bits/stdc++.h>
using namespace std;

string tmp;
vector<string> vect;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	getline(cin, tmp);
	string word = "";
	bool tag = false;
	for (int i = 0; i < tmp.size(); i++) {
		if (tag) {
			word += tmp[i];
			if (tmp[i] == '>') {
				tag = false;
				vect.push_back(word);
				word = "";
			}
		}
		else {
			if (tmp[i] == '<') {
				tag = true;
				reverse(word.begin(), word.end());
				vect.push_back(word);
				word = "<";
			}
			else if(tmp[i] == ' '){
				reverse(word.begin(), word.end());
				word += tmp[i];
				vect.push_back(word);
				word = "";
			}
			else{
				word += tmp[i];
				if (i == tmp.size() - 1) {
					reverse(word.begin(), word.end());
					vect.push_back(word);
				}
			}
		}
	}
	for (string s : vect)
		cout << s;
	return 0;
}
