#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t; cin>> t;
  while(t--)
  {
    int n; cin >>n;
    int acum=0;
    while(n--)
      {
	int k; cin >> k;
	acum ^=k;
      }
    if(acum == 0)
      cout <<"First\n";
    else
      cout << "Second\n";
  }
}
