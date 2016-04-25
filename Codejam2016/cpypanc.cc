#include <bits/stdc++.h>
using namespace std;


string reduccao(string cad)
{
  string nueva="";
  char act = cad[0];
  nueva+=act;
  for(int i = 1 ; i < cad.size() ; ++i)
    {
      if(act != cad[i])
	{
	  nueva+=cad[i];
	  act= cad[i];
	}
    }
  return nueva;
}


int main()
{
  int n; cin >> n;
  for(int i = 0 ; i < n ; ++i)
    {
      int cnt=0;
      string nai,cad,towork,cpy;  cin >> cad;
      towork = reduccao(cad);
      cpy = towork;
      cout << towork << "\n";
    }
  return 0;
}
