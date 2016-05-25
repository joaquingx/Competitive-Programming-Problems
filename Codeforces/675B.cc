#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n,a,b,c,d; cin >> n >> a >> b >> c >> d;
  vector<ll> ks(4); ks[0] = a+b ; ks[1] = b+d ; ks[2] = c + d; ks[3] = c+a;
  sort(ks.begin(),ks.end());
  ll dd = ks[3]-ks[0];
  if(dd >= n)
    cout << "0\n";
  else
    cout << (n-dd) * n << "\n";
  return 0;
}
