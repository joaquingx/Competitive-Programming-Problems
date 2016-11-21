#include <bits/stdc++.h>
using namespace std;

int cnvt(char a)
{
  return int(a-'0');
}


void justgo(int i,string &pat)
{
  int j;
  for(j = i ; j >= 0 ; --j)
    {
      if( pat[j] == '9')
	{
	  pat[j]=0;
	}
      else
	{
	  ++pat[j];
	  break;
	}
    }
  if(j < 0)
    {
      cout << 1;
    }
  for(int j = 0 ; j<= i ; ++j)
    {
      if(pat[j]==0)
	cout << 0;
      else
	cout << pat[j];
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n,k,hito=-1,cnt=0; cin >> n >> k;
  string pat ; cin >> pat;
  int pos = pat.find(".");
  for(int i = pos+1 ; i < pat.size() ; ++i)
    {
      if(pat[i] >= '5')
	{
	  hito = i;
	  break;
	}
    }
  if(hito != -1)
    {
      for(int i  = hito - 1 ; i > pos ; --i)
	{
	  if(pat[i+1] <= '4')
	    break;
	  if(cnt >= k)
	    break;
	  ++pat[i];
	  pat[i+1] = 0;
	  ++cnt;
	}
    }
  if(cnt < k and pat[pos + 1] >= '5')
    {
      justgo(pos-1,pat);
    }
  else
    {
      for(int i= 0 ;i < pat.size() ; ++i)
	{
	  if(pat[i] == 0)
	    break;
	  cout << pat[i];
	}
    }
  cout << "\n";
}













