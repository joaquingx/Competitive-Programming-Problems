#include <bits/stdc++.h>

using namespace std;

int main()
{
  int mch = 0;
  int ans = 0;
  int v[1000];
  memset(v,0,sizeof v);
  for(int i = 0 ; i < 5 ; ++i)
    {
      int l; cin >> l;
      ans+=l;
      ++v[l];
      if(v[l] >= 2 and v[l] <= 3)
	mch = max(v[l]*l,mch);
    }
  cout << ans - mch << "\n";
  return 0;
}
