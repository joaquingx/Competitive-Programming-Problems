#include <bits/stdc++.h>
using namespace std;

map<char , int > bu;
void init()
{
  for(int i = 0 ;i <= 26 ;++i)
    {
      bu['a' + i] = i;
    }
}

int main()
{
  init();
  string pat; cin >> pat;
  int ans=0;
  char curr = 'a';
  for(int i =0 ; i < pat.size() ; ++i)
    {
      int carr = max(bu[pat[i]],bu[curr])- min(bu[curr],bu[pat[i]]);
      int carrr =min(bu[pat[i]],bu[curr])- max(bu[curr],bu[pat[i]]);
      ans += min( carr , 26 + carrr);
      // cout << ans << "\n";
      curr = pat[i];
    }
  cout << ans <<"\n";
  return 0;
}

