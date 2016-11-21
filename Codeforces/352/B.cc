#include <bits/stdc++.h>
#define MAXN 26
using namespace std;

int main()
{
  string pat;
  int n,ans=0,cub[MAXN]; cin >> n;
  memset(cub,0,sizeof cub);
  cin >> pat;
  if(n>26)
    {
      cout << -1 << "\n";
      return 0;
    }
  for(int i = 0 ;i < pat.size() ; ++i)
    {
      ++cub[pat[i]-'a'];
    }
  for(int i= 0 ; i < 26 ; ++i)
    {
      if(cub[i] > 1)
	ans += cub[i]-1;
    }
  cout << ans << "\n";
  return 0;
}
