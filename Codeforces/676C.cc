#include <bits/stdc++.h>
using namespace std;

int main()
{
  string pat;
  int n,k; cin >> n >> k;
  cin >> pat;
  int ans = -1;
  for(int j = 0 ; j < 2 ; ++j)
    {
      int pnt = 0,cnt=0;
      for(int  i = 0 ; i < pat.size() ; ++i)
	{
	  if(pat[i] == char('a'+j))
	    {
	      if(cnt >= k)
		{
		  while(pat[pnt] != char('a'+j) and pnt < pat.size())
		    {
		      ++pnt;
		    }
		  ++pnt;
		}
	      ++cnt;
	    }
	  ans = max(ans,i-pnt+1);
	}
    }
  cout << ans << "\n";
  return 0;
}
