#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;

int main()
{
  int n; cin >> n;
  ll c=0; v.resize(n)  ;
  for(int i = 0 ;i < n ; ++i)
    {
      cin >> v[i];
      c += (v[i]-1);
      if(c%2 == 0)
	cout << "2\n";
      else
	cout << "1\n";
    }
  return 0;
}
