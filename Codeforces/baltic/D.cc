#include <bits/stdc++.h>
#define MAXN 510
using namespace std;
int dis[MAXN][MAXN];
char matrix[MAXN][MAXN];
int dx[]= {1,0,-1,0};
int dy[] = {0,1,0,-1};
int n,m,a,b;

void bfs(int x,int y)
{
  memset(dis,-1,sizeof dis);
  dis[x][y] = 0;
  queue< pair<int,int> > Q;
  Q.push({x,y});
  while(!Q.empty())
    {
      int x = Q.front().first,  y = Q.front().second; Q.pop();
      for(int i = 0 ; i < 4 ; ++i)
	{
	  int nx = x + dx[i], ny = y+dy[i];
	  if(nx < n and nx >= 0 and ny >= 0 and ny < m and dis[nx][ny] == -1
	     and matrix[nx][ny] != '#')
	    {
	      int cost= ((nx + ny) % 2 == 0 ? a  : b ) ;
	      dis[nx][ny] = dis[x][y] + cost;
	      Q.push({nx,ny});
	    }
	}
    }
  // for(int i = 0 ;i < n ; ++i)
  //   {
  //     for(int j = 0 ;j < m ; ++j)
  // 	cout << dis[i][j] << " ";
  //     cout << "\n";
  //   }
}

int main()
{
  cin >> m >> n >> a >> b;
  for(int i = 0 ; i < n; ++i)
    for(int j = 0 ;j < m ; ++j)
      cin >> matrix[i][j];
  bfs(0,0);
  if(dis[n-1][m-1] == -1)
    cout << "IMPOSSIBLE\n";
  else
    cout << dis[n-1][m-1] << "\n";
  return 0;
}
