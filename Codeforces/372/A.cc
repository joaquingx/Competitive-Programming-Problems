#include <bits/stdc++.h>
#define MAXN int(1e5+1)
using namespace std;

int main()
{
  int n,c,a[MAXN]; cin >> n >> c;
  for(int i = 0; i < n ; ++i)
    {
      cin >> a[i];
    }
  int carry = a[0],ans=1;
  for(int i = 1; i< n ; ++i)
    {
      if((a[i] - a[i-1]) > c)
	ans = 1;
      else
	++ans ;
    }
  cout << ans << "\n";
  return 0;
}
