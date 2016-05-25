#include <bits/stdc++.h>
#define MAXN int(4*1e5)
using namespace std;


int main()
{
  vector<int> v(MAXN);
  int n,k; cin >> n >> k;
  int pnt = 0, cnt= 0;
  for(int  i = 0 ; i < n ; ++i)
    cin >> v[i];
  int ix = 0, iy = 0 ,ans=-1;;
  for(int i = 0 ; i < n ; ++i)
    {
      if(v[i] == 0)
	{
	  if(cnt  >= k)
	    {
	      while(v[pnt] != 0 and pnt < n)
		++pnt;
	      ++pnt;
	    }
	  ++cnt;
	}
      if(i - pnt + 1 > ans)
	{
	  ix = pnt;
	  iy = i;
	  ans = i - pnt + 1;
	}
    }
  cout << ans << "\n";
  for(int i = 0 ; i < n ; ++i)
  {
    if(i >= ix and i <= iy)
      cout << 1 << " ";
    else
      cout << v[i] << " ";
  }
  cout << "\n";
  return 0;
}
