#include <bits/stdc++.h>
using namespace std;

int main()
{
  string res,n,m; cin >> n >> m;
  
  for(int i= 0 ; i < n.size() ; ++i)
    {
      int nn = n[i]-'0', mm = m[i]- '0';
      res += abs(nn-mm) + '0';
    }
  cout << stoi(res) << "\n";
  return 0;
}
