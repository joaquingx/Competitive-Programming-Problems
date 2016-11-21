#include <bits/stdc++.h>
#define MAXN int(110)
using namespace std;
vector<int> v(MAXN),vin;
multiset<int> s;

int main()
{
  int n ;cin >> n;
  for(int i = 0 ;i < n ; ++i)
    {
      cin >> v[i];
      s.insert(v[i]);
    }
  int idx = 0;
  // cout << *(s.begin()) << "\n";
  // for(auto it = s.begin() ; it != s.end() ; ++it)
  //   cout << *(it) << " ";
  // cout << "\n";
  while(!s.empty())
    {
      int num = find(v.begin(), v.end(), *(s.begin())) - v.begin();
      while(num != 0)
  	{
  	  cout << num+idx << " " << num+idx+1 << "\n";
	  swap(v[num],v[num-1]);
  	  --num;
  	}
      v.erase(v.begin());
      s.erase(s.begin());
      ++idx;
    }
  return 0;
}
