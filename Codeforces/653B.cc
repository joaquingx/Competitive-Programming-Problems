#include <bits/stdc++.h>
using namespace std;
int cnt=0;
vector< vector<string> > mapa(6);
int solve(int tam, string pat,int n)
{
  if(pat.size() == n)
    ++cnt;
  else
    {
      for(int i = 0 ; i <  mapa[int(pat[0]-'a')].size() ; ++i )
	{
	  string b = mapa[int(pat[0]-'a')][i];
	  for(int i = 1; i < pat.size() ; ++i)
	    b += pat[i];
	  solve(tam+1,b,n);
	}
    }
}

int main()
{
  int n,q; cin >> n >> q;
  for(int i = 0 ; i < q ; ++i)
    {
      string a,b; cin >> a>> b;
      mapa[int(b[0]-'a')].push_back(a);
    }
  solve(1,"a",n);
  cout << cnt << "\n";
  return 0;
}
