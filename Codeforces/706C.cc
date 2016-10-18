#include <bits/stdc++.h>
#define MAXN int(1e5+10)
using namespace std;
typedef long long ll;
#define INF ll(1e15+10)
ll dp[MAXN][2],v[MAXN];
string pat[MAXN];

bool islex(string &a , string &b)
{
  int n = min(a.size(), b.size() );
  for(int i = 0 ; i < n ; ++i)
    {
      if(int(b[i]) > int(a[i]))
	{
	  return 0;
	}
      if(int(a[i]) > int(b[i]))
	{
	  return 1;
	}
    }
  return a.size() >= b.size() ;
}


int main()
{
  ios_base::sync_with_stdio(0);
  int n; cin >> n;
  for(int i =0  ; i < n ; ++i)
    cin >> v[i];
  for(int i = 0 ;i < n ; ++i)
    {
      cin >> pat[i];
    }
  for(int i  = 0 ; i < MAXN ; ++i)
    for(int j = 0 ; j < 2 ; ++j)
      dp[i][j] = INF;
  dp[0][0] = 0;
  dp[0][1] = v[0];
  for(int i = 1; i < n ; ++i)
    {
      bool cag=0;
      string aux1 = pat[i-1];
      string aux2 = pat[i];
      reverse(aux1.begin() , aux1.end());
      reverse(aux2.begin() , aux2.end());
      if(pat[i] >= pat[i-1])
	{
	  cag = 1;
	  dp[i][0] = min(dp[i][0],dp[i-1][0]);
	}
      if(pat[i] >= aux1)
	{
	  cag  = 1;
	  dp[i][0] = min(dp[i][0],dp[i-1][1]);
	}
      if(aux2 >= pat[i-1])
	{
	  cag = 1;
	  dp[i][1] = min(dp[i][1],dp[i-1][0] + v[i] );
	}
      if(aux2 >= aux1)
	{
	  cag = 1;
	  dp[i][1] = min(dp[i][1],dp[i-1][1] + v[i] );
	}
      if(!cag)
	{
	  cout << -1 << "\n";
	  return 0;
	}
    }
  //prueba
  ll ans  = min(dp[n-1][0],dp[n-1][1]);
  if(ans >= INF)
    cout << -1 << "\n";
  else cout << min(dp[n-1][0],dp[n-1][1]) << "\n";
  return 0;
}
