#include <bits/stdc++.h>
#define MAXN 60
using namespace std;
int n,t,lleno,tam;
vector<int> v(MAXN),lvl(MAXN);

void solve(int j, int porc)
{
  if(v[j] == lleno)
    {
      solve(j+lvl[j],porc/2);
      solve(j+lvl[j]+1,porc/2);
    }
  else
    {
      v[j] += porc;
    }
  
}


int main()
{
  cin >>n >> t;
  lleno = 1 << (n-1);
  tam = (n*(n+1))/2;
  int cnt = 1,cntt=0;
  for(int i = 1 ; i <= tam ; ++i)
    {
      ++cntt;
      lvl[i] = cnt;
      if(cnt == cntt)
	{
	  cntt = 0;
	  ++cnt;
	}
    }
  for(int i = 0 ; i < t ; ++i)
    {
      // for(int j = 1 ; j  <= tam  ; ++j)
      solve(1,lleno);
    }
  int ans=0;
  for(int i = 0 ; i <= tam ; ++i)
    {
      // cout << v[i] << " ";
      if(v[i] == lleno)
	++ans;
    }
  cout << ans << "\n";
  // for()
    
}
