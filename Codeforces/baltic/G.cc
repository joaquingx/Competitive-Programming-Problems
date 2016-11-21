#include <bits/stdc++.h>
using namespace std;

int main()
{
  string pat,movs,res;
  int n,x,m; cin >> n  >> x;
  cin >> pat;
  cin >> m;
  cin >> movs;
  for(int i  = x-1,j = 0; j <= movs.size(); ++j)
    {
      res += pat[i];
      if(j < movs.size())
	{
	  if(movs[j] == 'R')
	    i++;
	  else
	    --i;
	}
    }
  cout << res << "\n";
  return 0;
}
