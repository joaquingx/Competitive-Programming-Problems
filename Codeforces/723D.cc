#include <bits/stdc++.h>
#define MAXN 51
using namespace std;
char matrix[MAXN][MAXN];
bool es=0;
int vis[MAXN][MAXN];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector< vector< pair<int,int> > > cnx;
vector< pair<int,int> > nn;
int n , m , k ;

void dfs(pair<int,int> u)
{
  if(u.first == n - 1 or u.second == m-1 or u.first == 0 or u.second == 0)
    es=1;
  vis[u.first][u.second] = 1;
  nn.push_back(u);
  for(int i = 0 ; i < 4 ; ++i)
    {
      int x = u.first + dx[i] ;
      int y = u.second + dy[i] ;
      if(x < n and x >=0 and y < m and y >= 0 and matrix[x][y] != '*' and !vis[x][y])
	{
	  dfs({x,y});
	}
    }
}

int main()
{
  cin >> n >> m >> k;
  memset(vis,0,sizeof vis);
  for(int i = 0;i < n ; ++i)
    for(int j = 0 ; j < m ; ++j )
      cin >> matrix[i][j];
  for(int i = 0;i < n ; ++i)
    for(int j = 0 ; j < m ; ++j )
      if(!vis[i][j] and matrix[i][j] == '.')
	{
	  // cout << i << " " << j << "\n";
	  nn.clear();
	  es = 0;
	  dfs({i,j});
	  if(!es)
	    {
	      // cout << i << " " << j << "\n";
	      cnx.push_back(nn);
	    }
	}
  int ans = 0;
  int act = cnx.size();
  vector< pair<int,int > > it;
  for(int i = 0 ; i < cnx.size() ; ++i)
    it.push_back({cnx[i].size(),i});
  sort(it.begin() , it.end());
  int ii = 0;
  while(act > k)
    {
      int idx = it[ii].second;
      ans += cnx[idx].size();
      for(int i = 0 ; i < cnx[idx].size() ; ++i)
	{
	  // cout << cnx[idx][i].first << " "  << cnx[idx][i].second << "\n";
	  matrix[cnx[idx][i].first][cnx[idx][i].second] = '*';
	}
      --act;
      ++ii;
    }
  cout << ans << "\n";
  for(int i= 0 ;i < n ; ++i)
    {
      for(int j = 0 ; j < m  ; ++j)
	cout << matrix[i][j] ;
      cout << "\n";
    }
  return 0;
}
