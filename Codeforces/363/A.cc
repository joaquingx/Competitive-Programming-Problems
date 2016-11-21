#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int main()
{
  char m[MAXN][MAXN];
  int n,k,cnt=0,fil[MAXN],col[MAXN] ; cin >> n >> k;
  memset(fil,0,sizeof fil);
  memset(col,0,sizeof col);
  for(int i= 0 ;i < n ; ++i)
    for(int j = 0 ; j < k ; ++j)
      {
	cin >> m[i][j];
	if(m[i][j]== '*')
	  {
	    ++cnt;
	    ++fil[i];
	    ++col[j];
	  }
      }
  for(int i = 0 ;i < n ; ++i)
    {
      for(int j = 0 ; j < k ; ++j)
	{
	  int rpta = fil[i] + col[j];
	  if(m[i][j]=='*')
	    --rpta;
	  if(rpta == cnt)
	    {
	      cout << "YES\n";
	      cout << i+1 << " " << j+1 << "\n";
	      return 0;
	    }
	}
    }
  cout << "NO\n";
  return 0;
}
