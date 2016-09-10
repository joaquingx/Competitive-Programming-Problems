#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; cin >> n;
  set<char> vc;
  string pat; cin >> pat;
  for(int i = 0 ; i < pat.size() ; ++i)
    {
      vc.insert(pat[i]);
    }
  set<char> rpta;
  int cntW[1000];
  memset(cntW,0,sizeof cntW);
  int ans=10000000;
  int ptr1=0,ptr2=0;
  for(int i = 0 ; i < pat.size() ; ++i)
    {
      ++cntW[pat[i]] ;    
      while(cntW[pat[ptr1]]> 1)
	{
	  --cntW[pat[ptr1]];
	  ++ptr1;
	}
      rpta.insert(pat[i]);
      if(rpta.size() == vc.size())
	ans = min(ans,i-ptr1+1);
    }
  cout << ans << "\n";
  return 0;
}
