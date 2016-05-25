#include <bits/stdc++.h>
using namespace std;
map<string,int> mapa;
vector<string> pals(3);

// int whatis(string ht)
// {
//   string table = "<table>";
//   string tr = "<tr>"
// }
int cnt = 0;
int id(string pat, int j)
{
  int pos = 1;
  string mine="";
  for(int i = j+1 ; pat[i] != '>' ; ++i)
    {
      if(pat[i] == '/')
	pos = -1;
      else
	mine += pat[i];
    }
  cout << mine << "\n"
  if(pos == -1)
    {
      if(mine == "/td")
	{
	  ++cnt;
	}
      if(mine == "/table")
	{
	  return 1;
	}
    }
  if(mapa.count(mine) != 0)
    mapa[mine] = pos;
  else mapa[mine] += pos;
  return 0;
}


int main()
{
  pals[0] = "table";
  pals[1] = "tr";
  pals[2] = "td";
  vector<int> rpta;
  string html="", pat;
  while(cin >> pat) html+=pat;
  for(int i = 0 ; i < html.size() ; ++i)
    {
      if(html[i] == '<')
	{
	  if(id(html,i) == 1)
	    {
	      rpta.push_back(cnt);
	      cnt = 0;
	    }
	}      
    }
  sort(rpta.begin() , rpta.end());
  for(int i = 0 ; i < rpta.size() ; ++i)
    cout << rpta[i] << " ";
  cout << "\n";
  return 0;
}
