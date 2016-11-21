#include <bits/stdc++.h>
#define MAXN int(1e5+100)
using namespace std;

int main()
{
  
  int n, m ,k,fil[MAXN],col[MAXN],timefil[MAXN],timecol[MAXN],opc,kk,color ; cin >> n >> m >> k;
  memset(timefil,-1,sizeof timefil);
  memset(timecol,-1,sizeof timecol);
  memset(fil,0,sizeof fil);
  memset(col,0,sizeof col);
  for(int i = 0;i < k ; ++i)
    {
      cin >> opc >> kk >> color;
      --kk;
      if(opc == 1)
	{
	  fil[kk] = color;
	  timefil[kk]= i;
	}
      else
	{
	  col[kk] = color;
	  timecol[kk]= i;
	}
    }
  for(int i = 0 ;i < n ; ++i)
    {
      for(int j = 0 ; j < m ; ++j)
	{
	  if(timefil[i] > timecol[j])
	    cout << fil[i];
	  else
	    cout << col[j];
	  cout << " ";
	}
      cout << "\n";
    }
  return 0;
}
