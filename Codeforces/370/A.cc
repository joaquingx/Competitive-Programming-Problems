#include <bits/stdc++.h>
#define MAXN int(1e5+10)
using namespace std;

int main()
{
  vector<int>ans;
  int n,v[MAXN]; cin >> n;
  for(int i= 0 ;i < n ; ++i)
    cin >> v[i];
  int c = 0,idx=0,k;
  for(int i =  n-1 ; i >= 0 ; --i)
    {
      if(idx % 2 == 0)
	{
	  c -= k;
	  k = v[i]-c;
	}
      else
	{
	  c += k;
	  k = v[i]+c;
	}
      // cout << c << "\n";
      ans.push_back(k);
      ++idx;
    }
  for(int i=n-1 ; i >= 0 ; --i)
    {
      cout << ans[i] << " ";
    }
  cout << "\n";
  return 0;
}
