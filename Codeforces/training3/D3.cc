#include <bits/stdc++.h>
#define MAXN int(50000+10)
using namespace std;
typedef long long ll;
ll ans[MAXN][MAXN],v[MAXN];
int cnt[MAXN];

void init(int n)
{
  memset(ans,0,sizeof ans);
  for(int i = 1 ;i <= n ; ++i)
    {
      ++cnt[v[i]];
      for(int j = 1 ; j <= n ; ++j)
	{
	  ans[i][j] = ans[i][j-1] + cnt[v[j]];
	}
    }

  // for(int i = 1 ;i <= n ; ++i)
  //   {
  //     for(int j = 1 ; j <= n ; ++j)
  // 	printf("%lld ",ans[i][j]);
  //     printf("\n");
  //   }
  
}

ll query(int r1 , int r2)
{
  return ans[r1][r2];
}


int main()
{
  ios_base::sync_with_stdio(0);
  int n,q,l1,l2,r1,r2;
  scanf("%d",&n);
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
