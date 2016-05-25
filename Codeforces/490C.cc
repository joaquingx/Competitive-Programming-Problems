#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnvt(char let)
{
  return let - '0';
}

int main()
{
  ios_base::sync_with_stdio(0);
  string pat;
  ll last,damelo=-1,finn=0;
  ll a,b;
  cin >> pat;
  cin >> a >> b;
  vector<bool> mark(pat.size(),0);
  ll yo = cnvt(pat[0]) % a;
  last  = pat.size();
  for(int i = 1 ; i < pat.size() ; ++i)
    {      
      if(yo == 0 and pat[i] !='0')
	mark[i] = 1;
      yo = (yo%a*10%a + cnvt(pat[i])%a) % a;
      // cout << yo << " el yo !\n";
    }
  ll acum = 1%b,acumant=1%b;
  for(int i = pat.size()-1 ; i >= 0; --i)
    {
      if(mark[i])
	{
	  // cout << pat[i] << "\n";
	  ll me = cnvt(pat[i])%b;
	  for(int j = i+1 ; j < last ;++j)
	    {
	      me = (me%b*10%b + cnvt(pat[j])%b )% b;
	      acum = (acum%b * 10%b) % b;
	    }
	  acum = (acum%b * 10%b) % b;
	  // cout << me << "mememem\n";
	  ll actual = ( me%b*acumant%b + finn % b) % b;
	  // cout << actual << "\n";
	  if( actual == 0)
	    {
	      damelo = i;
	      break;
	    }
	  last = i; acumant = acum;finn = actual;
	}
    }
  if(damelo != -1)
    {
      cout << "YES\n";
      for(int i = 0 ; i < damelo ; ++i)
	cout << pat[i];
      cout << "\n";
      for(int i = damelo ; i < pat.size() ; ++i)
	cout << pat[i];
      cout << "\n";	
    }
  else
    cout << "NO\n";
  return 0;
}
