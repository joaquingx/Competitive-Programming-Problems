#include <bits/stdc++.h>
#define MAXN 101
#define INF 100000
using namespace std;
int dp[MAXN][MAXN*MAXN][MAXN];
vector<int> a,b;
vector< pair < int , int > > c;
bool cmp( pair <int , int > a , pair < int , int > b)
{
  if(a.second == b.second)
    return a.first > b.first;
  return a.second > b.second;
}

void init()
{
  for(int i = 0 ; i < MAXN ; ++i)
    for(int j = 0 ; j < MAXN * MAXN ; ++j)
      dp[i][j] = -1;
}


int main()
{
  init();
  int n ,m ,cnt=0; cin >> n;
  a.resize(n); b.resize(n);
  for(int i = 0 ;i  < n ; ++i)
    {
      cin >> a[i];
      cnt+=a[i];
    }
  for(int i = 0  ;i < n; ++i)
    {
      cin >> b[i];
      dp[1][b[i]] = a[i];
    }
  bool flag=0;
  int bot;
  for(int i = 2 ; i <=n ; ++i)
    {
      for(int j = 1 ; j <= MAXN * MAXN ; ++j)
	{
	  for(int k = 0 ; k < n ; ++k)
	    {
	      int cap = b[k];
	      if(   (dp[i-1][j-cap] != -1 and dp[1][cap] != -1)  and (j - cap) != cap)
		dp[i][j] = max(dp[i][j], dp[i - 1][j - cap] + dp[1][ cap ]);
	    }
	  if(j >= cnt and dp[i][j] != -1  and !flag)
	    { bot = i; flag = 1;}
	}
    }
  // for(int i = 1 ;i  <= n ; ++i)
  //   {
  //     for(int j = 1 ; j <= 80 ; ++j)
  // 	cout << dp[i][j] << " " ;
  //     cout << "\n";
  //   }
  int k=-1;
  for(int i = 1 ; i <= 100  ; ++i)
    {
      cout <<  i << ": "<< dp[bot][i] << "\n";
      k = max( dp[bot][i],k);
    }
  cout << "\n";
  cout << bot << " " << abs(k-cnt) << "\n";
  return 0;
}
