#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=-1,n,m,k;

void bs(ll a , ll b)
{
  if(b-a > 1)
    {
      // cout << a << " " << b << "\n";
      ll med = (a+b)/2, medl = (a+med-1)/2, medr = (med+1+b)/2,rl,rr;
      ans = max((n/(med+1))*  (k - med+1 > 0 ? m/(k-med+1) : 1 ),ans  );
      rl = (n/(medl+1))*(k - medl +1> 0 ? m/(k-medl+1) : 1 );
      rr = (n/(medr+1))*(k - medr +1> 0 ? m/(k-medr+1) : 1 );
      if(rl > rr )
	bs(a,med-1);
      else
	bs(med+1,b);
    }
}

int main()
{
  cin >> n >> m >>  k;
  if(n+m-2 <= k)
    {
      cout << "-1\n";
      return 0;
    }
  ans = max(n/(k+1)*m,m/(k+1)*n);
  // cout << ans << "\n";
  bs(1,k);
  cout << ans << "\n";
  return 0;
}

