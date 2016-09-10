#include <bits/stdc++.h>
using namespace std;

string dp[]={"1869","6198","1896","9186","9168","6189","8691"};

void erase(int a,string & pat)
{
  
  for(int i =0 ; i< pat.size() ; ++i)
    {
      if(pat[i] == a)
	{
	  pat.erase(i,1);
	  break;
	}
    }
}


int main()
{
  string pat; cin >> pat;
  erase('1',pat);
  erase('6',pat);
  erase('8',pat);
  erase('9',pat);
  int gg = 1,rem=0,mod=7;
  string rr="";
  for(int i = 0 ; i < pat.size() ; ++i)
    {
      if(pat[i] != '0')
	{
	  rem = (rem +(gg%mod*int(pat[i]-'0')%mod)) % mod;
	  gg = (gg * 10)% mod;
	  rr += pat[i];
	}
    }
  reverse(rr.begin(), rr.end());
  cout << rr;
  cout << dp[rem];
  for(int i = 0 ; i < pat.size() ; ++i)
    {
      if(pat[i] == '0')
	cout << 0;
    }
  cout << "\n";
  return 0;
}
