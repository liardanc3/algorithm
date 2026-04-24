#include <iostream>
#include <vector>
using namespace std;
vector<int>::iterator iter;
long long sum(vector<int>& a) {
	long long ans = 0;
	for (iter = a.begin(); iter != a.end(); iter++)
		ans += *iter;
	return ans;
}