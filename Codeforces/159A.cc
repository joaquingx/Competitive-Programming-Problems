#include <bits/stdc++.h>
using namespace std;

int main()
{
  map< pair<string,string> , vector<int> > m;
  set< pair<string,string> > ans;
  int n,d; cin >> n >> d;
  for(int i = 0 ;i < n ; ++i)
    {
      int c;
      string a, b; cin >> a >> b >> c;
      m[{a,b}].push_back(c);
      if(m.count({b,a}) != 0)
  	{
	  for(int i = 0 ; i < m[{b,a}].size() ; ++i)
	    {
	      int it = m[{b,a}][i];
	      if(c-it <= d and c-it > 0)
		{
		  if(ans.find({b,a}) == ans.end() and ans.find({a,b}) == ans.end() )
		    {
		      ans.insert({a,b});
		      break;
		    }
		}
	    }
  	}
    }
  cout << ans.size() << "\n";
  for(auto it = ans.begin(); it != ans.end() ; it++)
    {
      cout << it->first << " " << it->second << "\n";
    }
  return 0;
}
