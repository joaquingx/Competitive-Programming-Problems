#include <bits/stdc++.h>
using namespace std;


int cnvt(char a)
{
  return int(a - 48);
}

int ronda(string &pat, int i)
{
  int j;
  for(j = i ; j >= 0 ;)
    {
      if(pat[j] == '9')
	{
	  pat[j] = '0';
	  pat[j+1] = '0';
	  --j;
	}
      else
	{
	  pat[j] = pat[j] + 1;
	  pat[j+1] = '0';
	  break;
	}
    }
  return j;
}


int main()
{
  int n,k,idx,hito=-1; cin >> n >> k;
  string pat; cin >> pat;
  bool punto=0;
  for(int i = 0 ; i < n ; ++i)
    {
      if(punto)
	{
	  if(cnvt(pat[i]) >= 5)
	    {
	      hito = i;
	      break;
	    }
	}
      if(pat[i] == '.')
	{
	  punto=1;
	  idx = i;
	}
    }
  if(hito == -1)
    {
      cout << pat << "\n";
      return 0;
    }
  punto = 0;
  int cnt=0,aver=n+1;
  int i;
  for(i = hito-1 ; i >= 0 ;)
    {
      if(i == idx)
	{
	  punto = 1;
	  --i;
	  continue;
	}
      int sig;
      if(punto)
	sig = pat[i+2];
      else sig = pat[i+1];
      if(cnvt(sig) >= 5)
	{
	  // cout << "entro\n";
	  aver = ronda(pat,i);
	  ++cnt;
	  if(cnt >= k)
	    break;
	  --i;
	}
      else
	break;
      if(punto)
	break;
    }
  if(aver <  0)
    cout << 1;
  if(pat[idx+1] == '0' or pat[idx] == '0')
    for(int j = 0 ; j < n ; ++j)
      {
	if (j == idx)
	  break;
	cout << pat[j];
      }
  else
    for(int j = 0 ;j <= i  ; ++j)
      {
	cout << pat[j];
      }
  cout << "\n";
  return 0;
}
