#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
vector< string > ans;

inline void insert(int x)
{
  ans.push_back("insert " + to_string(x) );
  s.insert(x);
}

inline void getMin(int x)
{
  // cout << "entre\n";
  while(!s.empty() and *(s.begin()) < x)
    {
      s.erase(s.begin());
      ans.push_back("removeMin");
    }
  if( s.empty() or *(s.begin()) > x)
    {
      ans.push_back("insert "  + to_string(x));
      s.insert(x);
    }
  ans.push_back("getMin "  + to_string(x));
}

inline void removeMin()
{
  if(s.empty())
    {
      s.insert(0);
      ans.push_back("insert 0");
    }
  s.erase(s.begin());
  ans.push_back("removeMin");
}


int main()
{
  ios_base::sync_with_stdio(0);
  // cin.tie(NULL);
  int n,c; scanf("%d",&n);
  char pat[100];
  for(int i = 0;i < n ; ++i)
    {
      scanf("%100s",pat);
      if(pat[0] == 'r')
	{
	  removeMin();
	  continue;
	}
      scanf("%d",&c);
      if(pat[0] == 'i')
	insert(c);
      if (pat[0] ==  'g')
	getMin(c);
    }
  printf("%d\n",ans.size());
  for(int i = 0 ;i < ans.size() ; ++i)
    printf("%s\n",ans[i].c_str());
  return 0;
}

