#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define PI 3.14159265
typedef double dd;

struct point
{
  dd x,y;
  point(dd nx , dd ny) { x  = nx ; y = ny; };
  point(){};
};
point origin; // origin point to convex hull

bool operator <(point A , point B);
point operator +(point A , point B);
point operator -(point A , point B);
dd operator *(point A, point B);
dd operator ^(point A, point B);
dd area(vector<point> & P );
dd norma(point A);
dd angle(point A, point B);
dd lineTopoint(point A ,point B , point C);
bool cmpcross(point A , point B);
bool cmpatan(point A , point B);
point getOrigin(vector<point> & P);
vector<point> ConvexHull(vector<point> & P);

// All points represent vectors
point card[4] = { point(1,0), point(0,1), point(-1,0) , point(0,-1)};

int main()
{
  vector<point> P;
  for(int i = 0 ; i < 3 ; ++i)
    {
      double x,y; cin >> x >> y;
      P.push_back(point(x,y));
    }
  P.push_back(P[0]); P.push_back(P[1]);
  if( (P[1] - P[0]) * (P[2] - P[0]) == 0 or
      (P[0] - P[1]) * (P[2] - P[1]) == 0 or
      (P[0] - P[2]) * (P[1] - P[2]) == 0      
    )
    {
      cout << "RIGHT\n";
      return 0;
    } 
  for(int i = 0  ; i < 3 ; ++i)
    {
      for(int j = 0 ; j < 4 ; ++j)
	{
	  point nv = (P[i]+card[j]);
	  if( (nv.x == P[i+1].x and nv.y == P[i+1].y) or
	      (nv.x == P[i+2].x and nv.y == P[i+2].y) ) continue;
	  point ab = (P[i+1]-nv);
	  point ac = (P[i+2]-nv);
	  point ba = (nv - P[i+1]);
	  point bc = (P[i+2] - P[i+1]);
	  point ca = (nv-P[i+2]);
	  point cb = (P[i+1] - P[i+2])	    ;
	  if(ab * ac == 0 or ba * bc == 0 or ca*cb == 0)
	    {
	      cout << "ALMOST\n";
	      return 0;
	    }
	}
    }
  cout << "NEITHER\n";
  return 0;
}

bool operator<(point A, point B)
{
  return norma(A)  < norma(B);
}
point operator +(point A , point B)
{
  return point(A.x+B.x,A.y+B.y);
}

point operator -(point A ,point B)
{
 return point(A.x - B.x , A.y - B.y);
}

dd operator *(point A , point B) // dot product
{
  return A.x * B.x + A.y * B.y;
}

dd operator ^(point A , point B) // cross product
{
  return A.x * B.y - A.y * B.x;
}

dd area(vector< point > & P) // area between two vectors
{
  sort(P.begin() , P.end() , cmpatan);
  P.push_back(P[0]);
  dd acum=0;
  for(int i = 0 ; i < P.size()-1 ; ++i) // n es el numero de puntos(posiblemente mas el primer punto
    {                          // para evitar ifs
      acum += (P[i] ^ P[i+1]) ;
    }
  return abs(acum/2);
}
dd norma(point A)
{
  return sqrt( (A.x)*(A.x) + (A.y)*(A.y) );
}

dd angle( point A , point B)
{
  // cout <<  norma(A)*norma(B)  << "\n"; 
  return acos( (A*B) / (norma(A)*norma(B)) ) ;
}


dd lineTopoint(point A , point B, point C, bool segment) // AB defines the line and C is the point
{
  point AB = B-A; point AC = C-A; point BC = C-B;
  dd dist = (AB^AC)/norma(AB);
  if(segment)
    {
      if(AB * BC > 0)
	return norma(BC);
      if( (A-B) * (A-C) > 0)
	return norma(A-C);
    }
  return abs(dist);
}

bool cmpatan(point A, point B)
{
  if( atan2(A.y,A.x) == atan2(B.y, B.x) )
    {
      return A < B;
    }
  return (atan2(A.y,A.x) < atan2(B.y, B.x));
}
bool cmpcross(point x, point y)
{
  point pnt(1,0);
  if(x.x == origin.x and x.y  == origin.y)
    return 1;
  if(y.x  == origin.x and y.y == origin.y)
    return 0;
  if(angle(pnt,x-origin) == angle(pnt,y-origin))
    {
      // cout << x.x <<" "<< x.y << "   " << y.x << " "<< y.y<< "\n" ;
      return (origin - x) <  (origin - y);
    }
  return  angle(pnt,x-origin) < angle(pnt,y-origin);
}

point getOrigin(vector<point> & P)
{
  point orig = P[0];
  for(int i = 1 ; i < P.size() ; ++i)
    {
      if(P[i].y < orig.y)
	{
	  orig = P[i];
	}
      if(P[i].y == orig.y)
	{
	  if(P[i].x < orig.x)
	    orig = P[i];
	}
    }
  return orig;
}

vector< point > ConvexHull( vector<point> & P)
{
  vector<point> ans;
  if(P.size() < 3 ) return P;
  origin =  getOrigin(P);
  // cout << "origen: "<<origin.x << origin.y << "\n";
  sort(P.begin(), P.end(),cmpcross);
  // for(int i = 0 ; i < P.size() ; ++i)
  //   cout << i << ": "<< P[i].x << " " << P[i].y << "\n";
  stack< point > pila;
  pila.push(P[0]);  pila.push(P[1]);
  for(int i = 2 ; i < P.size();)
    {
      point a = pila.top(),b;
      pila.pop();
      if(pila.size() >= 1)
	b = pila.top();
      pila.push(a);
      // cout << " a: "<< a.x << " " << a.y   << "b: " << b.x <<"   " <<  b.y  << "\n";
      if(pila.size() > 1 && ((P[i]-a)^(b-a)) <= 0)
	pila.pop();
      else
	{
	  pila.push(P[i]);
	  ++i;
	}      
    }
  while(!pila.empty())
    ans.push_back(pila.top()), pila.pop();
  return ans;
}
