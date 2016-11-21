#include <bits/stdc++.h>
using namespace std;

int main()
{
  int rcnt,lcnt,dcnt,ucnt;
  rcnt=lcnt=dcnt=ucnt=0;
  string pat;
  cin >> pat;
  if(pat.size() % 2 != 0)
    {
      cout << -1 << "\n";
      return 0;
    }
  for(int i = 0;i < pat.size() ; ++i)
    {
      if(pat[i] == 'R')
	++rcnt;
      if(pat[i] == 'L')
	++lcnt;
      if(pat[i] == 'D')
	++dcnt;
      if(pat[i] == 'U')
	++ucnt;
    }
  cout << (abs(ucnt-dcnt) + abs(lcnt-rcnt))/2 << "\n";
  return 0;
}
