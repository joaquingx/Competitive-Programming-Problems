#include <bits/stdc++.h>
using namespace std;


int main()
{
  int n,b,d; cin >> n >> b >>d ;
  int ans=0,c=0;
  for(int i = 0 ;i < n ; ++i)
    {
      int p; cin >> p;
      if(p <= b)
	c += p;
      if(c > d)
	{
	  ++ans;
	  c=0;
	}
    }
  cout << ans << "\n";
  return 0;
}
