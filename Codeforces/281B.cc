#include <bits/stdc++.h>
using namespace std;
// #define EPS double(1e-9)
#define MAXN double(1e11)
#define N int(1e6)
typedef long long ll;
double x,y,n,ans=MAXN;
int nn,dm;

// ll resta(int a, int  b , ll c , ll d)
// {
  
// }
void verify(double a,int source, int m)
{
  if(ans > a)
    {
      ans  = a;
      nn = source;
      dm = m;
    }
  if(ans == a)
    {
      if(m < dm)
	{
	  dm = m;
	  nn = source;
	}
      if(m == dm)
	{
	  if(source < nn)
	    {
	      dm = m;
	      nn = source;
	    }
	}
    }
  
}

void bs(int a, int b, int source)
{
  if(a <= b)
    {
      int m = (a + b)/2;
      // cout << source << "/" << m << "\n";
      if(x/y - double(source)/double(m) == 0 )
	{
	  verify( abs(x/y-double(source)/double(m)),source,m);
	  return ;
	}
      if(x/y - double(source)/double(m) < 0)
	{
	  verify( abs(x/y-double(source)/double(m)),source,m);
	  bs(m+1,b,source);
	}
      else
	{
	  verify( abs(x/y-double(source)/double(m)),source,m);
	  bs(a,m-1,source);
	}
	    
    }
}

int main()
{
  cin >> x >> y >> n;
  for(int i = 0 ; i < N ; ++i)
    {
      bs(1,n,i);
    }
  cout << nn << "/" << dm << "\n";
  return 0;
}
