#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main()
{
  ll a[3]; cin >> a[0] >> a[1] >> a[2] ;
  ll maximo = max(a[0],max(a[1],a[2]));
  ll ans=0;
  for(int i= 0 ;i < 3 ; ++i)
    {
      if(a[i] != maximo)
	ans += maximo - a[i]-1;
    }
  cout << ans << "\n";  
  return 0;
}
