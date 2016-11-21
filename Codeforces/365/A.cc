#include <bits/stdc++.h>
using namespace std;



int main()
{
  int n,cl=0,cr=0; cin >> n;
  for(int i = 0 ;i < n ; ++i)
    {
      int l,r; cin >> l >> r;
      if(l > r)
	++cl;
      else if (l < r)
	++cr;
    }
  if(cl > cr)
    cout << "Mishka\n";
  else if(cl < cr)
    cout << "Chris\n";
  else
    cout << "Friendship is magic!^^\n";
  return 0;
}
