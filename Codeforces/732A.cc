#include <bits/stdc++.h>
using namespace std;


int main()
{
  int n,k,ans,idx=0; cin >> n >> k;
  for(int i = n ; ; i+=n)
    {
      ++idx;
      if(i % 10 == k or i % 10 == 0)
	{
	  ans = idx;
	  break;
	}
    }
  cout << ans << "\n";
  return 0;
}
