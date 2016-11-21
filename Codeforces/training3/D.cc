#include <bits/stdc++.h>
#define MAXN int(50000+10)
#define SMAXN int(3)
using namespace std;
int v[MAXN];
int cnt[MAXN];
int ans[SMAXN][MAXN];
unordered_map<int,int> mapeo;

void init(int n)
{
  int contame=1;
  memset(cnt,0,sizeof cnt);
  memset(ans,0,sizeof ans);
  for(int i = 1 ; i <= n ; ++i)
    {
      ++cnt[v[i]];
      ++contame;
      // if(ontame == SMAXN)
      if(i % SMAXN == 0)
	{
	  int k = i/SMAXN;
	  for(int j = 1 ; j <= n ; ++j)
	  {
	    ans[k][j] = ans[k][j-1] + cnt[v[j]];
	  }
	  contame=1;
	}
    }
  // for(int i = 1  ;i*i <= n ; ++i)
  //   {
  //     for(int j = 1 ;j <= n ; ++j)
  // 	cout << ans[i][j] << " " ;
  //     cout << "\n";
  //   }
}

int range(int l1 , int r1 , int l2 , int r2)
{
  mapeo.clear();
  int ans = 0;
  for(int i = l1 ; i <= r1 ; ++i)
    ++mapeo[v[i]];
  for(int j = l2 ; j <= r2 ; ++j)
    if(mapeo.find(v[j]) != mapeo.end())
      ans += mapeo[v[j]];
  return ans;
}

int query(int r1 , int r2)
{
  int c1k = r1 / SMAXN ,c2k = r2 / SMAXN;
  int res1 = r1 % SMAXN, res2 = r2 % SMAXN;
  return ans[c1k][r2] + ans[c2k][r1] - ans[c2k][SMAXN*c1k] + range(SMAXN*c1k+1, SMAXN*c1k + res1 , SMAXN*c2k+1, SMAXN*c2k + res2);
}



int main()
{
  ios_base::sync_with_stdio(0);
  int n,q,l1,l2,r1,r2;
  scanf("%d",&n);
  init(n);
  for(int i = 1 ;i <= n; ++i)
    {
      scanf("%d",&v[i]);
    }
  scanf("%d",&q);
  for(int i  = 0 ; i < q ; ++i)
    {
      scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
      printf("%d\n",(query(r1,r2) - query(r1,l2-1) - query(l1-1,r2) + query(l1-1,l2-1)));
    }
  return 0;
}
