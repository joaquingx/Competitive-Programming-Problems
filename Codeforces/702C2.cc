#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> v1;
  set<int> v2;
  int n,m; cin >>n >> m;
  for(int i = 0 ; i < n; ++i)
    {
      int k; cin >> k;
      v1.push_back(k);
    }
  for(int i = 0  ; i < m ; ++i)
    {
      int k ; cin >> k;
      v2.insert(k);
    }
  int ans = -1;
  for(int i =0 ; i < n ; ++i)
    {
      set<int>::iterator upi = v2.lower_bound(v1[i]);
      int lv,uv;
      set<int>::iterator lowi;
      if(upi != v2.begin())
	{
	  --upi;
	  lowi = upi;
	  ++upi;
	}
      // cout << *(upi) << "\n";
      if(upi == v2.begin() )
	{
	  ans = max(ans,abs(v1[i] - *(upi)));
	}
      else if(upi == v2.end())
	{
	  ans = max(ans,abs(v1[i] - *(lowi)));
	  ++upi;
	}
      else
	{
	  // cout << abs(v1[i]-*(upi)) <<"\n";
	  // cout << v1[i]<< "\n";
	  ans = max(ans,min( abs(v1[i]-*(upi)) ,   abs(v1[i]-*(lowi)) )   );
	  ++upi;
	}
      // cout << ans << "\n";
    }
  cout << ans << "\n";
  return 0;
}
