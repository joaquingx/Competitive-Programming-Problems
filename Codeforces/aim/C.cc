#include <bits/stdc++.h>
using namespace std;


int main()
{
  string pat;
  cin >> pat;
  bool c =0;
  for(int i = 0 ;i < pat.size() ; ++i)
    {
      if(c)
	{
	  if(pat[i] > 'a')
	    --pat[i];
	  else
	    break;
	}
      else
      if(pat[i] > 'a')
	{
	  --pat[i];
	  c=1;
	}
    }
  if(!c)
    pat[pat.size()-1]='z';
  cout << pat << "\n";
  return 0;
}
