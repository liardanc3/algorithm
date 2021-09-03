#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<string> left,right;
	ifstream in("a.txt");
	string fstr = "", tmp;
	while (in.is_open()) {
		in >> tmp;
		fstr += tmp;
		if (tmp.compare("]") == 0) break;
	} //cout << fstr << '\n';
	char* cstr = new char[fstr.size()+1];
	copy(fstr.begin(), fstr.end(), cstr);
	cstr[fstr.size()] = '\0';
	char* ctmp = strtok_s(cstr, "\"{}[]:", &cstr);
	int check = 1;
	while (ctmp!=NULL) {
		check == 1 ? left.push_back(ctmp) : right.push_back(ctmp);
		check = (check + 1) % 2;
		ctmp = strtok_s(cstr, "\"{}[],:", &cstr);
	}
	for (int i = 0; i < left.size(); i++) {
		cout << left.at(i) << ": " << right.at(i) << '\n';
		if (i % 2 == 1)
			cout << '\n';
	}
}