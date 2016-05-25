#include <bits/stdc++.h>
#define MOD int(1e9+7)
using namespace std;
typedef long long ll;

int main()
{
  vector<ll> let(30,0);
  ll n;  cin >> n;
  string pat; cin >> pat;
  for(int i = 0 ; i < n ; ++i)
    {
      ++let[pat[i]-'A'];
    }
  ll maxi = -1,cnt=0,rpta=1;
  for(int i = 0 ; i < let.size() ; ++i)
    maxi = max(let[i],maxi);
  for(int i = 0 ; i < let.size() ; ++i)
    if(let[i]==maxi)
      ++cnt;
  for(int i = 0 ; i < n ; ++i)
    rpta =  (rpta%MOD * cnt%MOD)%MOD;
  while(rpta < 0)
    {
      rpta = (rpta + MOD)%MOD;
    }
  cout << rpta << "\n";
}
