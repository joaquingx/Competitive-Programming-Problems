#include <bits/stdc++.h>
using namespace std;
vector<string> pats;

int solve(string &rpta)
{
  bool si;
  while(rpta[rpta.size()-1] != '{')
    {
      for(int i = 0 ; i < pats.size() ; ++i)
	{
	  for(int j = 0 ; j < pats[i].size()-rpta.size()+1 ; ++j)
	    {
	      int cnt=0;
	      si = 1;
	      for(int k = j ; k < j + rpta.size() ; ++k)
		{
		  if(pats[i][k] != rpta[cnt])
		    si = 0;
		  ++cnt;
		}
	      if(si)
		break;
	    }
	  if(si)
	    break;
	}
      // cout << si <<  "  " << rpta << "\n";
      if(si)
	{
	  // cout << "jiji\n";
	  rpta[rpta.size()-1] = char(rpta[rpta.size()-1]+1);
	}
      if(!si)
	return 1;
    }
  return 0;
}


int main()
{
  int n; cin >> n;
  pats.resize(n);
  for(int i = 0 ; i < n ; ++i)
    {
      cin >> pats[i];
    }
  string rpta = "a";
  while(!solve(rpta))
    {
      bool nop=1;
      for(int i = 0 ; i < rpta.size() ; ++i)
	if(rpta[i] != 'z')
	  nop=0;
      if(rpta.size() >= 2 and !nop)
	{
	  rpta[rpta.size()-2] =  char(rpta[rpta.size()-2] +1);
	  rpta[rpta.size()-1] = 'a';
	}
      else
	{
	  rpta[rpta.size()-1] = 'a';
	  rpta += 'a';
	}
    }
  cout << rpta << "\n";
  return 0;
}
