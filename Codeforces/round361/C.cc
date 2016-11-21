#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN ll(8*1e18)
#define TAM ll(8*1e6)

ll cubes[TAM];

void init()
{
  for(ll  i = 2 ; i*i*i <= MAXN ; ++i)
    cubes[i] = i*i*i;
}

ll ways(ll key)
{
  ll ans=0;
  for(int i = 2 ; i *i * i <= MAXN ; ++i)
    {
      if(key < cubes[i])
	return ans;
      ans += key/cubes[i];
    }
  return ans;
}
//Lower Bound
ll bs(ll ini, ll fin , ll key)
{
  int cnt = 0;
  ll mid,res;
  while(fin > ini)
    {
      mid = ini +(fin-ini)/2;
      if(ways(mid) < key)
	{
	  ini = mid + 1;
	}
      else
	{
	  fin = mid;
 	}
      ++cnt;
    }
  // if(ways(ini) == key)
  //   return ini;
  return ini;
}


int main()
{
  init();
  ll n; cin >> n;
  // cout << ways(64) << "\n";
  if(ways(bs(2,MAXN,n)) == n )
    cout << bs(2,MAXN,n) << "\n";
  else
    cout << -1 << "\n";
  return 0;	     
}
