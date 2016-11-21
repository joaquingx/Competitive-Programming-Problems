#include <bits/stdc++.h>
using namespace std;

int main()
{
  set<int> s;
  int n; cin >> n;
  for(int i = 0;i < n ; ++i)
    {
      int l ; cin >> l;
      s.insert(l);
    }
  if(s.size() > 3)
    cout << "NO";
  else
    {
      if(s.size() == 3)
	{
	  vector<int> vv(s.begin() , s.end());
	  if( vv[2]-vv[1] == vv[1] - vv[0])
	    cout << "YES";
	  else
	    cout << "NO";
	}
      else      cout << "YES";
    }
  cout << "\n";
  return 0;
}
