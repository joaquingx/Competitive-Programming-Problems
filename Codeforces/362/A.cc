#include <bits/stdc++.h>
using namespace std;


int main()
{
  int t,x,s; cin >> t >> x >> s;
  if(s < t)
    {
      cout << "NO\n";
      return 0;
    }
  int res = s - t;
  if(res == 0)
    {
      cout << "YES\n";
      return 0;
    }
  if(res >= x)
    {
      if(res % x == 0 or res % x == 1)
	cout  << "YES\n";
      else
	cout << "NO\n";
    }
  else
    cout << "NO\n";
  return 0;
}
