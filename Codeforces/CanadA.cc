#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; cin >> n;
  string pat ; cin >> pat ;
  int  ans = 0;
  char c = pat[0];
  int i ;
  for(i = 1;i < n ; ++i)
    {
      if(c == '<')
	++ans;
      else
	break;
      c = pat[i];
    }
  if(c == '<' and i >= n-1)
    ++ans;
  c = pat[n-1];
  for( i= n - 2 ; i >= 0 ; --i)
    {
      if(c == '>')
	++ans;
      else
	break;
      c = pat[i];
    }
  if(c == '>' and i <= 0)
    ++ans;
  cout << ans << "\n";
  return 0;
}
