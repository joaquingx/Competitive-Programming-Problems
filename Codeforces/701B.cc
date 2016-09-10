#include <bits/stdc++.h>
#define MAXN int(1e5+10)
using namespace std;
typedef long long ll;
int main()
{
  ll row[MAXN],colum[MAXN];
  memset(row , 0  , sizeof row);
  memset(colum, 0 , sizeof colum);
  ll n,k; cin >> n >> k;
  ll cr=0,cc=0;
  ll rpta = n * n ;
  for(int i = 0 ; i < k ; ++i)
    {
      bool sr=0,sc=0;
      ll x,y; cin >> x >> y;
      if(!row[x])
	{
	  sr=1;
	  if(colum[y] == 1)
	    rpta -= (n-cc);
	  else
	    rpta -= (n-cc-1);
	}
      if(!colum[y])
	{
	  sc=1;
	  if(row[x] == 1)
	    rpta -= (n - cr);
	  else
	    rpta -= (n-cr-1);
	}
      if(sr)
	{
	  row[x] = 1;
	  cr++;
	}
      if(sc)
	{
	  colum[y] = 1;
	  cc++;
	}
      if(sc and sr)
	rpta -= 1;  
      cout << rpta << " ";
    }
  cout << "\n";
  return 0;
}
