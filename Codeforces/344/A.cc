#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int main()
{
  int n,a[MAXN],b[MAXN]; cin >> n;
  for(int i = 0 ;i < n ; ++i)
    {
      cin >> a[i];
    }
  for(int i = 0;i < n ; ++i)
    {
      cin >> b[i];
    }
  int res = -1;
  for(int  i =0 ;i < n ; ++i)
    {
      int ansa = 0,ansb=0;
      for(int j = i ; j < n ; ++j)
      {
	ansa = ansa | a[j];
	ansb = ansb | b[j];
      }
      res = max(res,ansa+ansb);
    }
  cout << res << "\n";
  return 0;
}
