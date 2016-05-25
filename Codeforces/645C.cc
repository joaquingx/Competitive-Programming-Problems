#include <bits/stdc++.h>
#define INF int(1e9)
using namespace std;
vector<int> rpta;
int ans;

void bs(int a, int b,int ini,int fin)
{
  if(a <=b )
    {
      int mit = (a+b)/2;
      int der = abs(rpta[mit]-rpta[fin]), izq  = abs(rpta[mit]-rpta[ini]);
      if(der > izq)
	{
	  ans = min(der,ans);
	  bs(mit+1,b,ini,fin);
	}
      else
	{
	  ans = min(izq,ans);
	  bs(a,mit-1,ini,fin);
	}
    }
}



int main()
{
  bool isfirst=1;
  string pat;
  int n,q;
  int cnt = 1;
  int rans=INF;
  cin >> n >> q;
  cin >> pat;
  for(int  i = 0 ; i < n ; ++i)
    {
      if(isfirst != 1)
	{
	  ++cnt;
	  if(pat[i] == '0')
	    rpta.push_back(cnt);
	}
      else
	if(pat[i] == '0')
	  {
	    rpta.push_back(cnt);
	    isfirst=0;
	  }
    }
  // for(int i = 0 ; i < rpta.size() ;++i)
  //   cout << rpta[i] << " " ;
  // cout << "\n";
  for(int i = 0 ; i < rpta.size() ; ++i)
    {
      ans = INF;
      if(i+q >= rpta.size())
	break;
      bs(i,i+q,i,i+q);
      // cout << ans << "\n";
      rans = min(ans,rans);
    }
  cout << rans << "\n";
  return 0;
}
