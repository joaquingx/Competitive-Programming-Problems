#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,ansa=0,ansb=0; cin >> n;
  string pat; cin >> pat;
  for(int i = 0 ; i < n ; ++i)
    {
      if(pat[i] == 'A')
	ansa++;
      else
	ansb++;
    }
  if(ansa > ansb)
    cout << "Anton";
  else
    {
      if(ansa == ansb)
	cout << "Friendship";
      else
	cout << "Danik";
    }
  cout << "\n";
  return 0;
}
