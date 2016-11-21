#include <bits/stdc++.h>
using namespace std;


int main()
{
  int T; cin >> T;
  while(T--)
    {
      string pat; cin >> pat;
      if(pat.size() < 2)
	{
	  cout << "YES\n";
	  continue;
	}
      if( (pat.size() & (pat.size() - 1 ))  == 0)
	{
	  bool flag=0;
	  // cout << (pat.size() & (pat.size() - 1 )) << "\n";
	  for(int i = 0 ; i < pat.size() ; i+=2 )
	  {
	    if(pat[i] == 'A' and pat[i+1]=='A')
	      {
		flag = 1;
	      }
	  }
	  if(flag)
	    cout << "NO\n";
	  else cout << "YES\n";
	}
      else
	cout << "NO\n";      
    }
  return 0;
}
