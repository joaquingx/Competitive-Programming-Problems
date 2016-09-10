#include <bits/stdc++.h>
#define MAXN int(1e5+10)
using namespace std;


int main()
{
  int v[MAXN];
  int n; cin >> n;
  for(int i = 0 ; i < n ; ++i)
    {
      cin >> v[i];
    }
  int ptr=0,ans=1,j=0;
  for(int i = 1 ; i < n ; ++i)
    {
      if(v[i] <= v[i-1] )
	ptr = i;
      while(v[ptr] > v[i] and ptr != i)
	++ptr;
      ans = max(i-ptr+1,ans);
    }
  cout << ans << "\n";
  return 0;
}
