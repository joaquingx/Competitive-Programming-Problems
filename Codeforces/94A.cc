#include <bits/stdc++.h>
using namespace std;


int main()
{
  map<string,int> mapa;
  string pat; cin >> pat;
  for(int i = 0 ; i < 10 ; ++i)
    {
      string p; cin >> p;
      mapa[p] = i;
    }
  int k = 0;
  for(int i = 0 ; i < 8 ; ++i)
    {
      string aux="";
      for(int j = k ; j < k+10 ; ++j)
	{
	  aux += pat[j];
	}
      cout << mapa[aux];
      k+=10;
    }
  cout << "\n";
  
}
