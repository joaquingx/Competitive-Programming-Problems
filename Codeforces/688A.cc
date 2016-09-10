#include <bits/stdc++.h>
using namespace std;

int main()
{
  int ans=0,cnt=0;
  int n,d; cin >> n >> d;
  for(int i  = 0 ; i <  d ; ++i)
    {
      string pat; cin >> pat;
      bool is = 0 ;
      for(int j =0  ; j < pat.size() ; ++j)
	if(pat[j] == '0')
	  is=1;
      if(!is)
	{
	  cnt=0;
	}
      else
	{
	  ++cnt;
	}
      ans = max(cnt,ans);
    }
  cout << ans << "\n";
  return 0;
}
