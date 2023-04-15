#include <bits/stdc++.h>
#define s std
typedef s::pair<int, int>T;s::priority_queue<T,s::vector<T>,s::greater<T>>q;int N,a,b,x,r;int main(){s::cin>>N;while(N--){s::cin>>a>>a>>b;q.push({a,b});}while(!q.empty()){T k=q.top();q.pop();if(k.second){r++;q.push({k.second,0});}else r--;x=s::max(x,r);}s::cout<<x;return 0;}