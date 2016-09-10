#include <bits/stdc++.h>
#define MAXN int(1e4+10)
// Problemo A
using namespace std;
int v[MAXN];

int main()
{
  int ans=0;
  int n,h; cin >> n >> h;
  for(int i = 0 ; i < n ; ++i)
    {
      int k; cin >> k;
      if(k > h )
	ans+=2;
      else
	ans+=1;
    }
  cout << ans << "\n";
  return 0;
}
