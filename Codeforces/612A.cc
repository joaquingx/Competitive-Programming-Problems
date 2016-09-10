#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll ans = 0;
  vector<ll> imp;
  int n; cin >> n;
  for(int i = 0 ; i < n ; ++i)
    {
      ll k; cin >> k;
      if(k % 2==0)
	ans += k;
      else
	imp.push_back(k);
    }
  sort(imp.begin() ,imp.end());
  if(imp.size() > 1)
    {
      int fin = (imp.size() % 2 == 0 ? 0 : 1);
      for(int i = imp.size()-1 ; i >= fin ; --i)
	ans+= imp[i];
    }
  cout << ans << "\n";
  return 0;
}
