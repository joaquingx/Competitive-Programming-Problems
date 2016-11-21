#include <bits/stdc++.h>
using namespace std;

int main()
{
  string pat;
  int n,happy=0,sad=0; cin >> n;
  cin >> pat;
  for(int i = 1 ; i < n ; ++i)
    {
      int gg = int(pat[i]);
      if(pat[i-1] == ':')
	{
	  if(gg == '(')
	    ++sad;
	  if(gg == ')')
	    ++happy;
	}
      if(pat[i-1] == '(')
	{
	  if(gg==':')
	    ++happy;
	}
      if(pat[i-1] == ')')
	{
	  if(gg==':')
	    ++sad;
	}      
    }
  if(sad > happy)
    cout << "SAD\n";
  if(sad < happy)
    cout << "HAPPY\n";
  if(sad == happy)
    cout << "BORED\n";
  return 0;
}
