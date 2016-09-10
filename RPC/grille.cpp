#include <bits/stdc++.h>
#define MAXN 11
using namespace std;

int main()
{
  string pat;
  int n; cin >> n;
  int matrix[MAXN][MAXN];
  char res[MAXN][MAXN];
  memset(matrix, 0 ,sizeof matrix);
  for(int i = 0 ; i < n ; ++i)
    {
      for(int j = 0 ; j < n ; ++j)
	{
	  res[i][j] = '*';
	}
    }	
  for(int i = 0 ; i < n ; ++i)
    {
      for(int j = 0 ; j < n ; ++j)
	{
	  char a; cin >> a;
	  if(a == '.')
	    matrix[i][j] = 1;
	}
    }
  if(n==0)
    {
      cout << "invalid grille\n";
      return 0;
    }
  cin >> pat;
  int cnt=0;bool is=1;
  for(int i = 0 ; i < n ; ++i)
    {
      for(int j = 0 ; j < n ; ++j)
	{
	  if(matrix[i][j] == 1)
	    {
	      is=0;
	    }
	}
    }
  if(is)
    {
      cout << "invalid grille\n";
      return 0;
    }
  int cc=0;
  vector<int> idx,jdx;
  while(cnt < pat.size() and cc < 1000000)
    {
      ++cc;
      for(int i = 0 ; i < n ; ++i)
	{
	  for(int j = 0 ; j < n ; ++j)
	    {
	      if(matrix[i][j] == 1)
		{
		  if(res[i][j] == '*')
		    {
		      res[i][j] = pat[cnt];
		      ++cnt;
		    }
		}
	    }
	}

      for(int i = 0 ; i < n ; ++i)
	{
	  for(int j = 0 ; j < n ; ++j)
	    {
	      if(matrix[i][j] == 1)
		{
		  matrix[i][j]  = 0;
		  idx.push_back(j);
		  jdx.push_back(n-i-1);
		}
	    }
	}
      for(int i = 0 ; i < idx.size() ; ++i)
	{
	  matrix[idx[i]][jdx[i]] = 1;
	}
      idx.erase(idx.begin(),idx.end());
      jdx.erase(jdx.begin(),jdx.end());
    }
  if(cnt != pat.size())
    {
      cout << "invalid grille\n";
      return 0;
    }
  string ans="";
  for(int i = 0 ; i < n ; ++i)
    {
      for(int j = 0 ; j < n ; ++j)
	{
	  ans += res[i][j];
	}
    }
  cout << ans << "\n";
  return 0;  
}

