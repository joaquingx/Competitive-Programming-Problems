#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;


int main()
{
  int n,k,ans[MAXN],a[MAXN],ans2=0; cin >> n >> k;
  for(int i= 0 ;i < n; ++i)
    cin >> a[i];
  for(int i= 0 ;i < n; ++i)
    ans[i] = a[i];
  // if(n == 1)
  //   {
  //     if(k - a[0] > 0)
  // 	cout << k - a[0] << "\n";
  //     else
  // 	cout << 0  << "\n";
  //     cout << max(a[0],k) << "\n";
  //     return 0;
  //   }
  for(int i = 1 ;i < n ; ++i)
    {
      if(a[i]+ ans[i-1] < k)
	{
	  ans[i] = a[i] + abs(k - (a[i] + ans[i-1]) );
	  ans2 += abs(k - (a[i] + ans[i-1]) );
	}      
    }
  cout << ans2 << "\n";
  for(int i = 0 ;i < n ; ++i)
    {
      cout << ans[i] << " ";
    }
  cout << "\n";
  return 0;
}
