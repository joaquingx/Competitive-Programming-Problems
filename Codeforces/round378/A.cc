#include <bits/stdc++.h>
using namespace std;
char vowels[] = {'A','E','I','O','U','Y'};
int main()
{
  string pat; cin >> pat;
  int cur = -1,ans=1;
  for(int i = 0 ;i < pat.size() ; ++i)
    {
      for(int j = 0 ; j < 6 ; ++j )
	if(pat[i] == vowels[j])
	  {
	    ans = max(ans,(i-cur));
	    cur = i;
	  }
    }
  ans = max(ans, int(pat.size()) - cur);
  cout << ans << "\n";
  return 0;
}
