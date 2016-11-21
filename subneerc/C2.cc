#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF ll(1e9)
ll n,mid;
ll bs1()
{
  ll ini = 0 , fin = INF;
  ll cnt = 0 ;
  while(true)
    {
      if(fin - ini <= 1)
	{
	  cout << ini << " " << 0 << "\n";
	  fflush(stdout);
	  cin >> n;
	  cout << fin  << " " << 0 << "\n";
	  fflush(stdout);
	  cin >> n;
	  if(n)
	    return fin;
	  else
	    return ini;
	}
      cout << ini << " " << 0 << "\n";
      fflush(stdout);
      cin >> n;
      cout << fin << " " << 0 << "\n";
      fflush(stdout);
      cin >> n;
      mid = (fin + ini)/2;
      if(n)
	ini = mid;
      else
	fin = mid;
    }
  return ini;
}


ll bs2()
{
  ll ini = 0 , fin = INF;
  while(true)
    {
      if(fin - ini <= 1)
	{
	  cout << 0 << " " << ini << "\n";
	  fflush(stdout);
	  cin >> n;
	  cout << 0 << " " << fin << "\n";
	  fflush(stdout);
	  cin >> n;
	  if(n)
	    return fin;
	  else
	    return ini;
	}
      cout << 0 << " " << ini << "\n";
      fflush(stdout);
      cin >> n;
      cout << 0 << " " << fin << "\n";
      fflush(stdout);
      cin >> n;
      mid = (fin + ini)/2;
      if(n)
	ini = mid;
      else
	fin = mid;
    }
  return ini;
}



int main(){
  ll r = bs2();
  ll l = bs1();
  cout << "A " << l << " " << r << "\n";
  return 0;
}
