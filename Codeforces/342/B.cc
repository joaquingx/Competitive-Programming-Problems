#include <bits/stdc++.h>
using namespace std;

int main()
{
  int ans = 0;
  string pat,match; cin >> pat;
  cin >> match;
  int n = match.size();
  for(int i =0 ;i < pat.size() ;)
    {
      if(i + n <= pat.size())
	{
	  // cout << n << "\n";
	  string patilla;
	  patilla = "";
	  patilla = pat.substr(i,n);
	  // cout << patilla << "\n";
	  if(patilla == match)
	    {
	      ++ans;
	      i = i + match.size();
	    }
	  else ++i;
	}
      else ++i;
    }
  cout << ans << "\n";
  return 0;
}
