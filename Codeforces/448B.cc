#include <bits/stdc++.h>
#define MAXN 30
using namespace std;
int cnvt(char c)
{
  return c-'a';
}

int main()
{
  bool posible=1;
  string s,t;
  int lets[MAXN],lett[MAXN];
  memset(lets,0, sizeof lets);
  memset(lett,0, sizeof lett);
  cin >> s >> t;
  for(int i = 0 ; i < s.size() ; ++i)
    ++lets[cnvt(s[i])];
  for(int i = 0 ; i < t.size() ; ++i)
    ++lett[cnvt(t[i])];
  if(s.size() < t.size())
    {
      cout << "need tree";
      return 0;
    }
  for(int i = 0 ; i < MAXN ; ++i)
    {
      if(lets[i] < lett[i])
	posible=0;
    }
  if(posible)
    {
      if(s.size() == t.size())
	cout << "array";
      if(s.size() > t.size())
	{
	  bool si=0;
	  int k = 0;
	  for(int i = 0 ; i < s.size(); ++i)
	    {
	      if(s[i] == t[k])
		k++;
	    }
	  if(k != t.size())
	    cout << "both";
	  else
	    cout << "automaton";
	}
    }
  else
    cout << "need tree";
  cout << "\n";
  return 0;
}

