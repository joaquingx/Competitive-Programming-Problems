#include <bits/stdc++.h>
using namespace std;
#define MAXN int(2*1e5+10)
typedef long long ll;
#define INF ll(1e18)
ll timo[MAXN],timo2[MAXN],mana[MAXN],mana2[MAXN];

int upper_bound(int n , ll c)
{
  int l = 0;
  int r = n;
  while (l < r)
    {
      int m = (l+r)/2;
      if (mana2[m] <= c)       /* Note use of < instead of <=. */
	l = m+1;
      else
	r = m;
    }
  return l;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ll n,m,k,x,s; cin >> n >> m >> k >> x >> s ;
  ll mini = n*x;
  for(int i = 0; i < m ; ++i)
    cin >> timo[i];
  for(int i = 0 ;i < m ; ++i)
    cin >> mana[i];
  for(int i= 0 ;i < k ; ++i)
    cin >> timo2[i];
  for(int i= 0 ; i < k ; ++i)
    cin >> mana2[i];
  for(int i = 0 ;i < k ; ++i)
    {
      if(mana2[i] > s)
	break;
      mini = min(mini,(n-timo2[i]) * x);
    }
  for(int i = 0 ;i < m ; ++i)
    {
      if(s - mana[i] >= 0)
	{
	  int searchi =  s - mana[i];
	  int upper = upper_bound(k,searchi)-1;
	  // if(upper == n)
	  //   upper
	  // if(upper == -1)
	  //   upper = 0;
	  mini = min(mini,n*timo[i]);
	  if(upper > -1)
	    {
	      if(mana[i] + mana2[upper]  <= s)
		{
		  mini = min(mini,(n-timo2[upper]) * timo[i] );
		}
	    }
	}
    }
  cout << mini << "\n";
  return 0;
}
