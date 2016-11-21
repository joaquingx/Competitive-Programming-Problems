#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main()
{
  ll n; cin >> n;
  ll cal=2,cc = 2,ini = 2;
  for(ll i =  1 ; i <= n ; ++i)
    {
      ll carry = (cal/i * cal) - (ini / i);
      // ll cost =  (carry - ini )/i;
      cc+=2;
      ini = cal;
      cal += cc;
      // cout << cost << "\n";
      cout  << carry << "\n";
    }
  return 0;
}
