#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll n,acum=0,cnt=0; 
  while(cin >> n)
    {
      if(n ==0)
	break;
      ++cnt;
      acum += n;
      ll how = acum/50;
      if(how >= 2)
	{
	  cout << "Input #" << cnt << ": Totally Sweet!\n";
	  acum -= how*50;
	}
      else if(how == 1)
	{
	  cout << "Input #" << cnt << ": Sweet!\n";
	  acum -= 50;
	}
    }
  return 0;
}
