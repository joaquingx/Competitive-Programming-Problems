#include <bits/stdc++.h>
using namespace std;

int main()
{
  string pat1,pat2;
  map<string , string> mapa;
  int n,m; cin >> n >> m;
  for(int i = 0; i < m ; ++i)
    {
      cin >> pat1 >> pat2;
      mapa[pat1] = pat2;
    }
  for(int i = 0 ; i < n ; ++i)
    {
      cin >> pat1 ;
      if(pat1.size() <= mapa[pat1].size())
	cout << pat1 << " ";
      else
	cout << mapa[pat1] << " ";
    }
  cout << "\n";
  return 0;
}
