#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,ix,iy; cin >> n;
  for(int i = 0 ; i < n ; ++i)
    {
      int c; cin >> c;
      if(c == n) ix = i;
      if(c == 1) iy = i;
    }
  cout << max(ix , max(iy  , max(n-1-ix,n-1-iy))) << "\n";
  return 0;
}
