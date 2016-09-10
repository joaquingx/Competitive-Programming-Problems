#include <bits/stdc++.h>
#define MAXN int(1e4+1)
using namespace std;
vector<string> pats;
int n,k;

bool isvowel(char c)
{
  if(c == 'a' or c=='e' or c =='i' or c == 'o' or c == 'u')
    return 1;
  return 0;
}

bool cadena(string &pat)
{
  string cad;
  int cnt = 0;
  for(int i = pat.size() - 1 ; ; --i)
    {
      if(i < 0)
	return 0;
      if(isvowel(pat[i]))
	++cnt;
      cad += pat[i];
      if(cnt == k)
	break;
    }
  reverse(cad.begin(),cad.end());
  pat = cad;
  return 1;
}

void compare(int i , int j, vector<vector <int> >& rel)
{
  string aux,aux2;
  for(int k = i ; k < j ; ++k)
    {
      aux = pats[k];
      if(cadena(aux))
	{
	  for(int f = k+1 ; f < j ; ++f)
	    {
	      aux = pats[k];
	      aux2 = pats[f];
	      cadena(aux); cadena(aux2);
	      if(aux == aux2)
		{
		  rel[k-i].push_back(f-i);
		  rel[f-i].push_back(k-i);
		}
	    }
	}
    }
}

int whatis(vector<vector <int> > &rel)
{
  if(rel[0].size() == 3)
    return 1;
  if(find(rel[0].begin(), rel[0].end() , 1) != rel[0].end() and find(rel[2].begin(), rel[2].end() , 3) != rel[2].end())
    return 2;
  if(find(rel[0].begin(), rel[0].end() , 2) != rel[0].end()  and find(rel[1].begin(), rel[1].end()  , 3) != rel[1].end())
    return 3;
  if(find(rel[0].begin(), rel[0].end() ,  3) != rel[0].end() and find(rel[1].begin() , rel[1].end(), 2) !=  rel[1].end())
    return 4;
  return 0;
}

int main()
{
  cin >> n >> k;
  for(int  i = 0 ; i < 4*n ; ++i)
    {
      string s; cin >> s;
      pats.push_back(s);
    }
  vector<int> dame;
  dame.push_back(1);
  for(int  i = 0  ; i < 4*n ; i+=4)
    {
      vector< vector<int> > rel;
      rel.resize(4);
      compare(i,i+4,rel);
      dame.push_back(whatis(rel));
      if(dame[i/4+1]==0)
	{
	  cout << "NO\n";
	  return 0;
	}
      if(dame[i/4] != 1 and dame[i/4+1] != 1  and dame[i/4+1] != dame[i/4])
	{
	  cout << "NO\n";
	  return 0;
	}
    }
  for(int i = 0 ; i < dame.size() ; ++i)
    {
      if(dame[i] == 2)
	{
	  cout << "aabb\n";
	  return 0;
	}
      if(dame[i] == 3)
	{
	  cout << "abab\n";
	  return 0;
	}
      if(dame[i] == 4)
	{
	  cout << "abba\n";
	  return 0;
	}
    }
  cout << "aaaa\n";
  return 0;
}
