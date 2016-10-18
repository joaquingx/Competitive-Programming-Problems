#include <bits/stdc++.h>
#include <stdio.h>
#define MAXN int(1e4+1)
using namespace std;
char matrix[MAXN][MAXN];
map< pair< int , int > , int> mapa;
vector<int> cnx;
int cnt=0,n,m,dx[] = {1,0,0,-1},dy[] = {0,1,-1,0};

void dfs(int u,int v, int cnn)
{  
  mapa[{u,v}] = cnn;
  ++cnt;
  for(int i =  0 ; i < 4 ; ++i)
    {
      int nu = u + dx[i] , nv = v + dy[i];
      if(nu < n and nu >=0 and nv < m and nv >= 0 and matrix[nu][nv] == '.' and mapa.count({nu,nv}) == 0)
	dfs(nu,nv,cnn);													  
    }
}

int solve(int u, int v)
{
  int rpta=0;
  vector<int> src;
  for(int i = 0 ; i < 4 ; ++i)
    {
      int nu = u + dx[i] , nv = v + dy[i];
      if(nu < n and nu >=0 and nv < m and nv >= 0 and matrix[nu][nv] == '.')
	{
	  if(find(src.begin(),src.end(),mapa[{nu,nv}]) == src.end())
	    {
	      int conexidad = mapa[{nu,nv}];
	      src.push_back(conexidad);
	      rpta += cnx[conexidad];
	    }
	  
	}
    }
  return rpta+1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m;
  // scanf("%d %d",&n,&m);
  for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ;j < m ; ++j)
      cin >> matrix[i][j];
      // scanf("%s",matrix[i]);

  int cn = 0;
  for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < m ; ++j)
      if(matrix[i][j] == '.' and mapa.count({i,j}) == 0)
	{
	  cnt = 0;
	  dfs(i,j,cn);
	  cnx.push_back(cnt);
	  ++cn;
	}
  for(int i = 0 ; i < n ; ++i)
    {
      for(int j = 0 ; j < m ; ++j)
      {
	if(matrix[i][j] == '*')
	  {
	    int rpta = solve(i,j);
	    // printf("%d",rpta%10);
	    cout << rpta % 10;
	  }
	else
	  // printf(".");
	  cout << ".";
      }
      // printf("\n");
      cout << "\n";
    }  
  return 0;
}
