#include <bits/stdc++.h>
#define MAXN int(1e5+10)
using namespace std;
typedef long long ll;
int n,k,mark[MAXN];
ll acum[MAXN],capam[MAXN],v[MAXN],cap[MAXN];
void init()
{
  memset(acum,0,sizeof acum);
  memset(capam,0,sizeof capam);
  memset(mark,0,sizeof mark);
  acum[1] = v[1];
  for(int i = 2;i <= n ; ++i)
    acum[i] = acum[i-1] + v[i];
  capam[1] = v[cap[1]];
  for(int i = 2 ; i <= k ; ++i)
    capam[i] = capam[i-1] + v[cap[i]];
}

ll rangeci(int l , int r)
{
  return acum[r] - acum[l-1];
}


ll rangeca(int l, int r, int ady1 , int ady2)
{
  ll sum = capam[r] - capam[l-1];
  if(mark[ady1])
    sum -= v[ady1];
  if(mark[ady2])
    sum -= v[ady2];
  return sum;
}

ll ady(int l)
{
  if(l == 1)
    return acum[2] + v[n];
  if(l == n)
    return v[n-1] + v[n] + v[1];
  return rangeci(l-1,l+1);
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> k;
  for(int i = 1 ;i <= n; ++i)
    {
      cin >> v[i];
    }
  for(int i = 1 ;i <= k ; ++i)
    {
      cin >> cap[i];
    }
  init();
  ll ans = 0;
  for(int i = 1 ; i <= n-1 ; ++i )
    {
      ans += (v[i] * v[i+1]);
    }
  ans += (v[n] * v[1]);
  // cout << ans << "\n";
  for(int i = 1 ; i <= k ; ++i)
    {
      int capi = cap[i],ady1,ady2;
      mark[capi] = 1;
      if(capi == 1)
	{ ady1 = n; ady2 = 2;}
      else if(capi == n)
	{	  ady1 = 1 ; ady2 = n-1;	}
      else {
	ady1 = capi -1;
	ady2 = capi + 1;
      }
      // cout << rangeci(1,n) << " " << ady(capi) << " " << rangeca(1,i-1,ady1,ady2) << "\n";
      ans += v[capi] * ( rangeci(1,n) - ady(capi) - rangeca(1,i-1,ady1,ady2) ) ;
    }
  cout << ans << "\n";
  return 0;
}
