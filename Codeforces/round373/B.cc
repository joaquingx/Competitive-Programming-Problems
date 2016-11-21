#include <bits/stdc++.h>
using namespace std;
vector<int> pat;
int n ; 
int solve(int c)
{
  int ans=0;
  int cnt[2];
  memset(cnt,0,sizeof cnt);
  for(int i = 0 ;i < n ;++i)
    {
      if(pat[i] != c)
	{
	  ++cnt[pat[i]];
	}
      c = 1 - c ;
    }
  ans = max(cnt[0],cnt[1]);
  return ans;
}


int main()
{
  cin >> n;
  for(int i = 0;i < n ; ++i)
    {
      char a ; cin >> a;
      if(a == 'r') pat.push_back(0);
      else
	pat.push_back(1);
    }
  int ans1 = solve(1);
  int ans2 = solve(0);
  // cout << ans1 << " " << ans2 << "\n";
  cout << min(ans1,ans2) << "\n";
  return 0;
}
