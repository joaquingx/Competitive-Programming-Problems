#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> v(12);
  int k; cin >> k;
  for(int i = 0 ; i < 12 ; ++i)
    cin >> v[i];
  sort(v.begin(), v.end() );
  int cnt=0,ans=0;
  for(int i = 11 ; i >= 0 ; --i)
    {
      if(ans >= k)
	{
	  cout << cnt << "\n";
	  return 0;
	}
      ++cnt;
      ans += v[i];
    }
  if(ans >= k)
    {
      cout << cnt << "\n";
      return 0;
    }
  cout << -1 << "\n";
  return 0;
}
