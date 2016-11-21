#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n,m ; cin >> n >> m;
  ll carry = m,strees=0;
  for(int i = 0 ;i < n ; ++i)
    {
      char c ; ll cant;
      cin >> c >> cant;
      if(c== '+')
	carry +=cant;
      else
	{
	  if(carry >= cant)
	    carry -= cant;
	  else
	    ++strees;
	}
    }
  cout << carry << " " << strees << "\n";
  return 0;
}
