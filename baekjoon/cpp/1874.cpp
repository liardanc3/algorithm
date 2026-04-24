#include <iostream>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int main() {
	int NO = 0;
	string answer = "";
	int num, tmp; cin >> num;
	queue<int> ans;
	for (int i = 0; i < num; i++) {
		cin >> tmp;
		ans.push(tmp);
	}
	stack<int> ST; int push;
	for (int i = 1; i <= num+1; i++)
	{
		push = 0;
		if (i != num + 1) {
			if (ST.empty() || ans.front() != ST.top()) {
				ST.push(i);
				push = 1;
				answer += "+\n"; continue;
			}
		}

		if(i!=num+1) i--;

		while (!ans.empty() && !ST.empty() && ans.front() == ST.top()) {
			ST.pop();
			ans.pop();
			answer += "-\n"; 
		}

		if (i == num + 1 && !ST.empty() && !ans.empty())
			NO = 1;
	}

	if (NO) cout << "NO";
	else cout << answer;

	return 0;
}