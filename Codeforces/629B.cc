#include <bits/stdc++.h>
#define MAXN 5100
#define N 400
using namespace std;


int main()
{
  int n; cin >> n;
  vector< pair<int,int> > v(MAXN);
  bool g[MAXN];
  memset(g,0,sizeof g);
  for(int i = 0 ; i < n; ++i)
    {
      int a,b;
      char k;
      cin >> k >> a >> b;
      if(k == 'M') g[i] = 1;
      v[i] = {a,b};
    }
  int ans=-1;
  for(int i = 0 ; i < N ; ++i)
    {
      int cntf=0,cntm=0;
      for(int j = 0 ; j < n ; ++j)
	{
	  if( v[j].first <= i and i <= v[j].second)
	    if(g[j]) cntm++;
	    else cntf++;
	}
      ans = max(ans , min(cntf,cntm));
    }
  cout << ans*2 << "\n";
  return 0;
}
