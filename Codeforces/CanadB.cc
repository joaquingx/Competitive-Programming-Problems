#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main()
{
  ll num;
  string pat,pp; cin >> pat;
  for(int i =0 ; i < pat.size() ; ++i)
    {
      if(pat[i] > 57)
	break;
      pp+=pat[i];
    }
  num = stoll(pp);
  ll ans = ( (num-1) / 4) * 16 ;
  ll nnum = (num) % 4;
  if(nnum == 0 or nnum == 2 )
    ans+=7;
  if(pat[pat.size() - 1] <= 'c')
    {
      ans +=3;
      ans +=((pat[pat.size() - 1] - 'a') +1) ;
    }
  else
    ans += 3 -  ((pat[pat.size() - 1] - 'd') ) ;
  cout << ans << "\n";
  return 0;
}
