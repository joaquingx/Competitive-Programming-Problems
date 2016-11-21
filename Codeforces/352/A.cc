#include <bits/stdc++.h>
using namespace std;


int main()
{
  string rpta;
  int n ; cin >> n;
  for(int i = 1 ; ; ++i)
    {
      // cout << to_string(i) << "\n";
      rpta += to_string(i);
      if(rpta.size() > 1001)
	break;
    }
  // cout << rpta;
  cout << rpta[n-1] << "\n";
  return 0;
}
