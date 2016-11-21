#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll a[4];
  for(int i = 0 ;i < 4 ; ++i)
    cin >> a[i];
  ll mini56 = 0,mini256=0,mini32=0;
  mini56 = min(a[2],a[3]);
  mini256 = min(mini56,a[0]);
  mini32= min(a[0]-mini256,a[1]);
  cout << ll(mini256*256 + mini32 * 32) << "\n";
  return 0;
}
