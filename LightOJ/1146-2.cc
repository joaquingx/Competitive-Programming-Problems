#include <bits/stdc++.h>
using namespace std;
typedef double dd;
typedef complex<double> point;

point puntos[4];

dd ternarysearch()
{
  dd left,right;

  left = 0;
  right= abs(puntos[1]-puntos[0]);

  dd vela = abs(puntos[1]-puntos[0]);
  dd velb = abs(puntos[3]-puntos[2]);
  
  point fst = puntos[0];
  point snd = puntos[2];

  //vectores unitarios
  point vunita = (puntos[1]-puntos[0])/abs(puntos[1]-puntos[0]);
  point vunitb = (puntos[3]-puntos[2])/abs(puntos[3]-puntos[2]);

  int cnt = 300;

  dd ans = 10000000;
  //ternary search itself
  while(cnt--)
    {
      dd m1 = left + (right-left)/3, m2 = right - (right-left)/3; // primer y segundo tercio
      dd t1 = m1/vela , t2 = m2/vela;
      
      point fpointa = fst+(vunita * m1) , spointa = fst+(vunita*m2);
      point fpointb = snd+(vunitb*(velb*t1)) , spointb = snd+(vunitb*(velb*t2));

      dd dist1 = abs(fpointb-fpointa) , dist2 = abs(spointb-spointa);

      if(dist1 < dist2)
	{
	  right = m2;
	  ans = min(ans,dist1);
	}
      else
	{
	  left = m1;
	  ans = min(ans,dist2);
	}
      
    }
  return ans;
}


int main()
{
  int n; scanf("%d",&n);
  for(int i = 1 ; i <= n ; ++i)
    {
      for(int j = 0 ; j < 4 ; ++j)
	{
	  dd a,b;
	  scanf("%lf %lf",&a,&b);
	  puntos[j] = point(a,b);
	}
      printf("Case %d: %.10lf\n",i,ternarysearch());      
    }
  
  return 0;
}
