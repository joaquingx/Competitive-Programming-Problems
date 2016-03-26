#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
string v1="<({[",v2=">)}]";

int clasi(char &a)
{
  if(a == '<' or a == '>')
    return 1;
  if(a == '(' or a == ')')
    return 2;
  if(a == '{' or a == '}')
    return 3;
  if(a == '[' or a == ']')
    return 4;
}

int dime(char &a,int &ti)
{
  bool gg;
  for(int i = 0 ; i < 4 ; ++i)
    if(a == v1[i])
      {
	gg=0;
	ti = clasi(a);
      }
  for(int i = 0 ; i < 4 ; ++i)
    {
      if(a == v2[i])
	{
	  gg=1;
	  ti = clasi(a);
	}
    }
  return gg;
}


int main()
{
  ios_base::sync_with_stdio(false);
  int cnt=0,ans=0;
  vector<int> in,ou;
  string str; cin >> str;
  for(int i = 0 ; i < str.size() ; ++i)
    {
      int omg;
      if(dime(str[i],omg) == 0)
	{
	  in.push_back(omg);
	  ++cnt;
	}
      else
	{
	  --cnt;
	  if(cnt<0)
	    {
	      cout << "Impossible\n";
	      return 0;
	    }
	  // cout << in.back() << "\n";
	  if(in.back() != omg)
	    {
	      ++ans;
	    }
	  in.pop_back();
	}
	
    }
  if(in.size() == 0)
    cout << ans << "\n";
  else
    cout << "Impossible\n";
  return 0;
}
