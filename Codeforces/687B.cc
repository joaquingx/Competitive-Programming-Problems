#include <bits/stdc++.h>
using namespace std;
#define MAXN int(1e6+100)
typedef long long ll;
int sieve[MAXN];
int cntP[MAXN];


inline void criba()
{
  memset(sieve, 0 , sizeof sieve);
  memset(cntP, 0 , sizeof cntP);
  for(int  i = 2 ; i*i <= MAXN; ++i )
    {
      if(!sieve[i])
	{
	  for(int j = i * i ; j <= MAXN ; j+=i)
	    {
	      sieve[j] = i;
	    }
	}
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  criba();
  ll n,k; cin >> n >> k;
  for(int i = 0 ; i < n ; ++i)
    {
      int c; cin >> c;
      while(c > 1)
  	{
  	  int p  = sieve[c];
	  if(p == 0)
	    {
	      cntP[c] = max(1,cntP[c]);
	      break;
	    }
  	  int cnt= 0 ;
  	  while(c % p == 0 )
  	    {
  	      ++cnt;
  	      c /= p;
  	    }
  	  cntP[p] = max(cnt,cntP[p]);
  	}      
    }
  while(k > 1)
    {
      int pk = sieve[k];
      if(pk == 0)
	{
	  // cout << cntP[k] << "\n";
	  if(cntP[k] == 0)
	    {
	      cout << "No\n";
	      return 0;
	    }
	  k = 1;
	  continue;
	}
      if(cntP[pk] <= 0)
  	{
  	  cout << "No\n";
  	  return 0;
  	}
      --cntP[pk];
      k /= pk;
    }
  cout << "Yes\n";
  return 0;
}
