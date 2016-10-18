#include <bits/stdc++.h>
#define MAXN int(11)
using namespace std;
int dx[] = {0,0,1,-1,0,0};
int dy[] = {1,-1,0,0,0,0};
int dz[] = {0,0,0,0,1,-1};
int n,m,k,ans=0,vis[MAXN][MAXN][MAXN];
char matrix[MAXN][MAXN][MAXN];
void dfs(int x,int y , int z)
{
  // cout << x<< y << z <<"\n";
  ++ans;
  vis[x][y][z] = 1;
  for(int i = 0 ;i < 6 ; ++i)
    {
      int nx = x+dx[i], ny = y+dy[i], nz = z+dz[i];
      if(nx >= 0 and nx < k and ny < n and ny >= 0 and nz >= 0 and nz < m and matrix[nx][ny][nz]== '.' and !vis[nx][ny][nz])
	{
	  dfs(nx,ny,nz);
	}
    }
}



int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> k >> n >> m;
  for(int i = 0 ; i < k ; ++i)
    for(int j= 0 ; j < n ; ++j)
      for(int l = 0 ; l < m ; ++l)
	{
	  cin >> matrix[i][j][l];
	  vis[i][j][l]  = 0;
	}
  int x,y; cin >> x >> y;
  dfs(0,--x,--y);
  cout << ans << "\n";
  return 0;
}
