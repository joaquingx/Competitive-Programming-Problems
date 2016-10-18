#include <bits/stdc++.h>
using namespace std;
vector<int> p,rating;

void dsuCreate(int u)
{
  p[u] = u;
  rating[u] = 0;
}

int dsuFind(int v)
{
  return (v == p[v]) ? v : (p[v] = dsuFind(p[v]) );
}

void dsuUnion(int u , int v)
{
  u = dsuFind(u);
  v = dsuFind(v);
  p[u] = v;  
}


int main()
{
  // ios_base::sync_with_stdio(0);
  // cin.tie(NULL);
  vector<int> ans;
  int n,m; scanf("%d %d",&n,&m);
  rating.resize(n);
  p.resize(n+1,0);
  ans.resize(n+1,0);
  for(int i = 1 ; i <= n ; ++i)
    dsuCreate(i);
  for(int i = 0 ;i < m ; ++i)
    {
      int l,r,x;
      scanf("%d %d %d",&l,&r,&x);
      for(int j = l ; j <= r ; )
	{
	  if(dsuFind(j) == j)
	    {
	      if( j <= x)
		dsuUnion(j,x);
	      else
		dsuUnion(j,r);
	      if(ans[j] == 0 or ans[j] == j)
		{
		  ans[j] = x;
		}
	    }
	  else
	    {	
	      j = dsuFind(j);
	      //dsuUnion(j,max(p[j],min(x,r)));
	      continue;
	    }
	  ++j;
	}
    }
  for(int i = 1 ;i <= n ; ++i)
    {
      if(ans[i] != i)
	printf("%d ",ans[i]);
      else
	printf("%d ",0);
    }
  printf("\n");
  return 0;
}
