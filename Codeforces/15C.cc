#include <bits/stdc++.h>
#define BITS 64
using namespace std;
typedef long long ll;

string binary(ll n)
{
  n+=1;
  string tobin;
  ll idx = 2,cnt=0;
  while(n/idx >  0)
    {
      ll prev = n / idx;
      ll modulus = n % idx;
      ll per = (prev*(idx/2));
      if(modulus > 0)
	per += ( modulus-(idx/2) > 0 ? modulus-(idx/2) : 0 ) ;
      tobin +=  ( per  % 2  == 0 ? '0' : '1' );
      idx *= 2;
    }
  tobin += ( (n-(idx/2)) %2 == 0 ? '0' : '1' ) ;
  for(int i = tobin.size() ; i <= BITS ; ++i)
    {
      tobin += '0';
    }
  reverse(tobin.begin() , tobin.end());
  return tobin;
}

ll xori(string a, string b)
{
  ll ans=0,cnt=1;
  for(int i = BITS ; i >= 0 ; --i )
    {
      ll aa = ll(a[i]-'0') , bb = ll(b[i] - '0');
      ans += (aa ^ bb)*cnt;
      cnt*= 2;
    }
  // cout << ans << "\n";
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  scanf("%d",&n);
  ll x, m,rpta=0;
  for(int i = 0 ; i < n ; ++i)
    {
      //asdsada
      scanf("%lld %lld",&x,&m);
      string ip = binary(x+m-1);
      string op = binary(x-1);
      // cout << ip << " " << op << "\n";
      ll my = xori(binary(x+m-1),binary(x-1));
      rpta ^= my;
    }
  // cout << rpta << "\n";
  if(rpta > 0)
    printf("tolik");
  else
    printf("bolik");
  printf("\n");
  return 0;
}
