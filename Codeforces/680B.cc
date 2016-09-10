#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;


int main()
{
  int n,k,v[MAXN],mark[MAXN],ans=0; cin >> n >> k; 
  for(int i = 0 ; i < n ; ++i)
    {
      cin >> v[i];
    }
  --k;
  memset(mark, 0 , sizeof mark);
  for(int i = 0 ; i < n ; ++i)
    {
      int idx = abs(k - i),cnt=0;
      if(mark[i] == 0)
	{
	  mark[i] = 1;
	  if(v[i] == 1)
	    {
	      ++cnt;
	      if(idx + k < n)
		{
		  mark[idx+k]=1;
		  if(idx+k != i)
		    {
		      if(v[idx+k] == 1)
			++cnt;
		      else
			cnt=0;
		    }
		}
	    }
	  else
	    {
	      cnt = 0;
	      if(idx + k < n)
		mark[idx+k] = 1;
	    }
	  ans+=cnt;
	}	
    }
  cout << ans << "\n";
  return 0;
}
