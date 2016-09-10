#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll n,k; cin >> n >> k;
  if(n % 2  == 0)
    {
      if(k > n/2)
	cout << (k - n/2)*2;
      else
	cout << k * 2 -1;
    }
  else
    {
      if(k > n/2 + 1)
	cout << (k - (n/2+1)) * 2;
      else
	cout << k * 2 - 1;
    }
  cout << "\n";
  return 0;
}
