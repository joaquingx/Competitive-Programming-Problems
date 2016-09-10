#include <bits/stdc++.h>
#define MAXN 10
#define INF double(1e9+10)
#define EPS double(1e-10)
using namespace std;
string pat[MAXN];
double v1[MAXN],v2[MAXN];
int mark[MAXN];

int main()
{
  int T; cin >> T;
  while(T--)
    {
      memset(mark, 0 ,sizeof mark);
      for(int i = 0 ; i < MAXN ; ++i)
	{
	  cin >> pat[i] >> v1[i] >> v2[i];
	}
      double mini = INF;
      for(int i = 5 ; i < MAXN ; ++i)
	{
	  if(v2[i] == 0)
	    mini = min(INF,mini);
	  else
	    mini = min(mini,v1[i]/v2[i]);
	}
      for(int i = 5 ; i < MAXN ; ++i)
	{
	  if(v2[i] == 0)
	    {
	      if(mini == INF)
		mark[i]= 1;
	    }
	  else
	    {
	      if(mini == v1[i]/v2[i])
		mark[i] = 1;
	    }
	}
      double x = double(1)/double(2);
      for(int i = 5 ; i < MAXN ; ++i)
	{
	  if(v2[i] != 0)
	    {
	      // cout <<(v1[i]/v2[i]) << "\n";
	      if(x > (v1[i]/v2[i]))
		mark[i] = 1;
	    }
	}
      x = double(1)/double(3);
      for(int i = 0 ; i < 5 ; ++i)
	{
	  if(v2[i] != 0)
	    {
	      // cout << x << "\n";
	      // cout <<(v1[i]/v2[i])  << " "<<  x << " "<< "\n";
	      if(x - (v1[i]/v2[i]) > EPS)
		mark[i] = 1;
	    }
	}
      for(int i = 0 ; i < MAXN ; ++i)
	{
	  if(mark[i] == 1)
	    {
	      cout << pat[i] << " plz uninstall\n";
	    }
	}
    }
  return 0;
}
