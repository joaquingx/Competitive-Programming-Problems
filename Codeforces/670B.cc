#include <bits/stdc++.h>
using namespace std;


int main()
{
  int n,k; cin >> n >> k;
  vector<int> p(n+1);
  for(int i = 1 ; i <= n ; ++i)
    {
      cin >> p[i];
    }
  int ans;
  for(int i = 1 , idx=1; ; )
    {
      if(idx >= k)
	{
	  ans = p[k];
	  break;
	}
      k-=i;
      i+= idx;
      idx+=1;
    }
  cout << ans << "\n";
  return 0;
}
