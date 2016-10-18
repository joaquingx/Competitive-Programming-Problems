#include <bits/stdc++.h>
#define MAXN 501
using namespace std;
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
char matrix[MAXN][MAXN];
int vis[MAXN][MAXN];
int c=0;
int n,m,k,cnt=0 ;

void dfs(int u,int v)
{
  if(c == cnt - k )
    return ;
  vis[u][v]=1;
  ++c;
  for(int i = 0 ; i < 4 ; ++i)
    {
      int nu = u + dx[i]; int nv = v + dy[i];
      if(nu < n and nu >= 0 and nv < m and nv >= 0 and vis[nu][nv] == 0 and matrix[nu][nv] == '.')
	{
	  dfs(nu,nv);
	}
    }
    
}
int main()
{
  for(int i = 0 ; i < MAXN ; ++i)
    for(int j = 0 ; j < MAXN ; ++j)
      vis[i][j] =0;
  cin >> n >> m >> k;
  int l,r;
  for(int i = 0 ;i < n ; ++i)
    for(int j = 0 ; j < m ; ++j)
      {
	cin >> matrix[i][j];
	if(matrix[i][j] == '.')
	  {
	    l = i; r = j;
	    ++cnt;
	  }
      }
  dfs(l,r);
  for(int i = 0 ;i < n ; ++i)
    {
      for(int j = 0 ; j < m ; ++j)
	{
	  if(matrix[i][j]== '.')
	    {
	      if(vis[i][j])
		cout << ".";
	      else
		cout << "X";
	    }
	  else
	    cout << matrix[i][j];
	}
      cout << "\n";
    }
  return 0;
}
