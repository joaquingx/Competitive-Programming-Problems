#include <bits/stdc++.h>
#define MAXN int(1e5)
using namespace std;
typedef long long ll;
vector<int> ans;

int main()
{
  int n; cin >> n;
  int k = n-1;
  for(int i = 1 ; i*i <= n ; ++i)
    {
      if(k % i == 0)
	{
	  ans.push_back(i);
	  if(i != k/i)
	    ans.push_back(k/i);
	}
    }
  sort(ans.begin(),ans.end());
  for(int i = 0 ; i < ans.size() ; ++i)
    cout << ans[i] << " ";
  cout << "\n";
  return 0;  
}

