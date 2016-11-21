#include <bits/stdc++.h>
#define MAXN int(50000+10)
#define SMAXN int(230)
using namespace std;
typedef long long ll;
ll v[MAXN];
int cnt[MAXN];
ll ans[230][MAXN];
// unordered_map<int,int> mapeo;

void init(int n)
{
  int counter = 0;
  memset(cnt,0,sizeof cnt);
  memset(ans,0,sizeof ans);
  for(int i = 1 ; i <= n ; ++i)
    {
      ++cnt[v[i]];
      ++counter;
      // if(i % SMAXN == 0)
      if(counter == SMAXN)
	{
	  int k = i/SMAXN;
	  for(int j = 1 ; j <= n ; ++j)
	  {
	    ans[k][j] = ll(ans[k][j-1] + cnt[v[j]]);
	  }
	  counter = 0;
	}
    }
}

ll range(int l1 , int r1 , int l2 , int r2)
{
  // mapeo.clear();
  ll ans = 0;
  for(int i = l1 ; i <= r1 ; ++i)
    for(int j = l2 ; j <= r2 ; ++j)
      if(v[i]==v[j])
	++ans;
  // for(int i = l1 ; i <= r1 ; ++i)
  //   ++mapeo[v[i]];
  // for(int j = l2 ; j <= r2 ; ++j)
  //   if(mapeo.find(v[j]) != mapeo.end())
  //     ans += mapeo[v[j]];
  return ans;
}

ll query(int r1 , int r2)
{
  int c1k = r1 / SMAXN ,c2k = r2 / SMAXN;
  int res1 = r1 - SMAXN*c1k , res2 = r2 - SMAXN*c2k;
  return ans[c1k][r2] + ans[c2k][r1] - ans[c2k][SMAXN*c1k] + range(SMAXN*c1k+1, SMAXN*c1k + res1 , SMAXN*c2k+1, SMAXN*c2k + res2);
}



int main()
{
  ios_base::sync_with_stdio(0);
  int n,q,l1,l2,r1,r2;
  scanf("%d",&n);
  // SMAXN = int(sqrt(n));
  for(int i = 1 ;i <= n; ++i)
    {
      scanf("%I64d",&v[i]);
    }
  init(n);
  scanf("%d",&q);
  for(int i  = 0 ; i < q ; ++i)
    {
      scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
      printf("%I64d\n",  (query(r1,r2) - query(r1,l2-1) - query(l1-1,r2) + query(l1-1,l2-1))  );
    }
  return 0;
}
