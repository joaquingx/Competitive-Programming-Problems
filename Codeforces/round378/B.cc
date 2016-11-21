#include <bits/stdc++.h>
using namespace std;
#define MAXN int(1e5+10)
int v[MAXN],c[MAXN],lefti,righty;

int main()
{
  int n; cin >> n;
  for(int i = 0 ;i < n; ++i)
    {
      cin >> v[i] >> c[i];
      lefti += v[i];
      righty += c[i];
    }
  int ans = abs(lefti - righty), idx = -1,nwl,nwr;
  for(int i = 0 ; i < n; ++i)
    {
      nwl = lefti - v[i] + c[i];
      nwr = righty - c[i] + v[i];
      if(abs(nwl-nwr) > ans)
	{
	  idx = i;
	  ans = abs(nwl-nwr);
	}
    }

  cout << idx +1<< "\n";
  
  return 0;
}
