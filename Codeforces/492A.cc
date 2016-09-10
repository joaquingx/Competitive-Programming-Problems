#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; cin >> n;
  int cnt = 0,i = 1,idx=2;
  while(1)
    {
      n -= i;
      // cout << n << "\n";
      if(n < 0)
	break;
      i += idx;
      // cout << i << "\n";
      ++idx;
      ++cnt;
    }
  cout << cnt << "\n";
}
