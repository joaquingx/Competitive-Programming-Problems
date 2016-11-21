#include <bits/stdc++.h>
#define MAXN 101
using namespace std;
string pat,v[MAXN];
vector<int> a(MAXN);
void init()
{
  for(int i = 0 ; i < pat.size() ; ++i)
    pat[i]= '?';
    
}

void llenar(char & c, char no)
{
  if(c != '?')
    {
      if(c != no)
	c = '?';
    }
}

bool matches(string p1 , string p2)
{
  for(int i = 0 ;i < p1.size() ; ++i)
    {
      if(p1[i] != '?')
	if(p1[i] != p2[i])
	  return 0;
    }
  return 1;
}

int main()
{
  bool sepuede=1;
  int n , m ; cin >> n >> m;
  for(int i = 0; i < n ; ++i)
    cin >> v[i];
  a.resize(m);
  for(int i = 0 ; i < m ; ++i)
    { cin >> a[i]; --a[i];}
  pat = v[a[0]];
  // cout << pat << "\n";
  for(int i = 1 ;i < m ; ++i)
    {
      // cout << pat << "\n";
      if(v[a[i]].size() != pat.size() )
	{ sepuede=0; break; }
      else
	{
	  for(int j = 0 ; j < pat.size() ; ++j)
	    llenar(pat[j],v[a[i]][j]);
	}
    }
  // cout << pat << "\n";
  for(int i = 0 ; i < n ; ++i)
    {
      if(pat.size() == v[i].size())
	{
	  if(matches(pat,v[i]))
	    {
	      // cout << v[i] << "\n";
	      if(find( a.begin() , a.end()  , i)  == a.end())
		{sepuede = 0 ; break;}
	    }
	}
    }
  if(sepuede)
    {
      cout << "Yes\n";
      cout << pat << "\n";
    }
  else
    cout << "No\n";
  return 0;
}
