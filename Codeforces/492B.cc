#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;
vector<double> v(MAXN);


int main()
{
  int n,l;  cin >> n >> l;
  for(int i = 0 ; i < n; ++i)
    scanf("%lf",&v[i]);
  sort(v.begin() , v.begin() + n);
  double ans = -1;
  if(n == 1)
    {
      printf("%.10lf\n",(max(v[0],l-v[0])));
      return 0;
    }
  for(int i = 0 ; i < n ; ++i)
    {
      double here;
      if(i == 0)
	{
	  here = max(v[i], (v[i+1]-v[i])/2);
	}
      else if(i == n-1)
	{
	  here = max(l - v[i] , (v[i]-v[i-1])/2 );
	}
      else
	{
	  here = max(abs(v[i]- v[i-1])/2 , abs(v[i] - v[i+1] )/2);
	}
      ans = max(ans,here);
    }
  printf("%.10lf\n",ans);
  return 0;
}
