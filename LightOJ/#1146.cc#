#include <bits/stdc++.h>
using namespace std;
typedef double dd;
dd a[2],b[2],c[2],d[2],vfirst,vsecond;

dd norm(dd x1, dd y1 , dd x2 , dd y2)
{
  dd x = abs(x2-x1);
  dd y = abs(y2-y1);
  dd z = x*x + y*y;
  return sqrt(z);
    
}


dd ternary()
{
  dd left,right,m1,m2,t1,t2,unitax,unitay,unitbx,unitby,pt1x,pt1y,pt2x,pt2y,pt3x,pt3y,pt4x,pt4y,dist1,dist2,ans=100000, leftfx,leftfy,leftsx,leftsy,rightsx,rightsy,rightfx,rightfy;
  vfirst = norm(a[0],a[1],b[0],b[1]);
  vsecond = norm(c[0],c[1],d[0],d[1]);
  // left = norm(0,0,a[0],a[1]);
  // right = norm(0,0,b[0],b[1]);
  left = 0;
  right = norm(a[0],a[1],b[0],b[1]);
  
  leftfx = a[0];  leftfy = a[1];
  rightfx = b[0];  rightfy = b[1];

  leftsx = c[0] ; leftsy = c[1];
  rightsx = d[0] ; rightsy = d[1];
  
  unitax = (b[0]-a[0])/vfirst;  unitay = (b[1]-a[1])/vfirst;
  unitbx = (d[0]-c[0])/vsecond; unitby = (d[1]-c[1])/vsecond;
  int count = 300;
  while(count--)
    {
      m1 = left + (right-left)/3;
      m2 = right - (right-left)/3;
      t1 = m1/vfirst;
      t2 = m2/vfirst;
      pt1x = leftfx + (unitax*m1); pt1y = leftfy + (unitay*m1);
      pt2x = leftfx + (unitax*m2); pt2y = leftfy + (unitay*m2);
      pt3x = leftsx + (unitbx*(t1*vsecond)); pt3y = leftsy + (unitby*(t1*vsecond));
      pt4x = leftsx + (unitbx*(t2*vsecond)); pt4y = leftsy + (unitby*(t2*vsecond));
      // cout << "pt1x: " <<pt1x << "  pt1y: " << pt1y << "\n";
      // cout << "pt2x: " <<pt2x << "  pt2y: " << pt2y << "\n";
      // cout << "pt3x: " <<pt3x << "  pt3y: " << pt3y << "\n";
      // cout << "pt4x: " <<pt4x << "  pt4y: " << pt4y << "\n";
      dist1 = norm(pt1x,pt1y,pt3x,pt3y); dist2 = norm(pt2x,pt2y,pt4x,pt4y);
      // cout << "distancia 1 : " << dist1 << " distancia 2 : " << dist2 << "\n";
      if(dist1 < dist2)
	{
	  right = m2;
	  ans = min(dist1,ans);
	}
      else
	{
	  left = m1;
	  ans = min(dist2,ans);
	}
    }
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n,re; scanf("%d",&n);
  re = n;
  while(n--)
    {
      scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&a[0],&a[1],&b[0],&b[1],&c[0],&c[1],&d[0],&d[1]);
      printf("Case %d: %.10lf\n",re-n,ternary());
    }
  return 0;
}
