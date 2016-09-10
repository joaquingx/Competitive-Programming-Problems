#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

int main()
{
  vector<int> v1,v2;
  int n,ans=0; cin >> n;
  for(int i = 0 ; i < n ; ++i)
    {
      int k; cin >> k;
      v1.push_back(k);
    }
  v2 = v1;
  sort(v2.begin() , v2.end());
  int may = v2[v2.size()-1];
  for(int i = 0 ; i < n ; ++i)
    {
      if(v1[i] == may)
	{
	  for(int j = i ; j >= 1 ; --j)
	    {
	      int aux = v1[j];
	      v1[j] =  v1[j-1];
	      v1[j-1] = aux;
	    }
	  ans += i;
	  break;
	}
    }
  int men = v2[0];
  for(int i = n-1 ; i >= 0 ; --i)
    {
      if(men == v1[i])
	{
	  ans += n - i -1;
	  break;
	}
    }
  cout << ans << "\n";
  return 0;
}
