#include <bits/stdc++.h>
using namespace std;


int main()
{
  int n, m ; cin >> n >> m;
  bool es = 1;
  for(int i= 0 ; i < n; ++i)
    for(int j = 0 ; j < m ; ++j)
      {
	char a;
	cin >> a;
	if(a != 'B' and a != 'W' and a != 'G')
	  es =0;
      }
  if(es)
    cout << "#Black&White\n";
  else
    cout << "#Color\n";
  return 0;
}
