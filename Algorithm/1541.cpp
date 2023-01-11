#include <bits/stdc++.h>
#include <string>
#include <string.h>
using namespace std;

int main() {
	string input;
	cin >> input;
	
	char* tmp = const_cast<char*>(input.c_str());
	char* input_right = NULL;
	char* input_left = strtok_r(tmp, "-", &input_right);
	int sum_left = 0;
	int sum_right = 0;
	char* tok_tmp = NULL;
	tok_tmp = strtok_r(input_right, "-+", &input_right);
	while (tok_tmp != NULL) {
		sum_right += stoi(tok_tmp);
		tok_tmp = strtok_r(input_right, "-+", &input_right);
	}
	tok_tmp = strtok_r(input_left, "-+", &input_left);
	while (tok_tmp != NULL) {
		sum_left += stoi(tok_tmp);
		tok_tmp = strtok_r(input_left, "-+", &input_left);
	}
	cout << sum_left - sum_right;
	return 0;
}

// visual studio strtok_s == gcc strtok_r