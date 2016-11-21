#include <bits/stdc++.h>
using namespace std;
#define INF 1e17
#define MAXN int(1e5+10)
#define EPS 1e-7
typedef pair<double,double> pd;

double dist(pd a, pd b)
{
  return sqrt((a.first - b.first) * (a.first - b.first) + (b.second - a.second)*(b.second - a.second));
}


int main()
{
  int idx[2],n;
  pd bottle[MAXN],p[2],rec;
  double ans=INF,better[2],dp[MAXN][4];
  better[0]= INF,better[1]=INF;
  for(int i = 0 ; i < 2 ; ++i)
    scanf("%lf %lf", &p[i].first,&p[i].second);
  scanf("%lf %lf", &rec.first,&rec.second);
  scanf("%d",&n);
  memset(dp,0,sizeof dp);
  for(int i = 1 ;i <= n ; ++i)
    {
      scanf("%lf %lf",&bottle[i].first,&bottle[i].second);
      double met1 = dist(p[0],bottle[i]), met2= dist(p[1],bottle[i]),
	met3 = dist(rec,bottle[i]);
      dp[i][0] = dp[i-1][0] + met3 * 2;
      if(i == 1)
	{
	  dp[i][1] = met1 + met3;
	  dp[i][2] = met2 + met3;
	  dp[i][3] = min(dp[i][1],dp[i][2]);
	}
      else
	{
	  dp[i][1] = min(dp[i-1][0] + met1 + met3,dp[i-1][1] + met3*2);
	  dp[i][2] = min(dp[i-1][0] + met2 + met3,dp[i-1][2] + met3*2);
	  dp[i][3] = min(dp[i-1][3] + met3* 2 , min(dp[i-1][1] + met2 + met3 , dp[i-1][2] + met1 + met3 ));
	}
    }
  for(int i = 1 ; i < 4 ; ++i)
    {
      // printf("%lf\n",dp[n][i]);
      ans = min(dp[n][i],ans);
    }
  printf("%.20f\n",ans);
  return 0;
}
