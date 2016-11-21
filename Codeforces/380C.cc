#include <bits/stdc++.h>
#define INF int(1e9)
#define N int(1e6+10)
#define NEUTRO 0
using namespace std;
int n; // tama;o del vector
// definicion ST.
int st[2*N],open[2*N],closed[2*N]; // solo se necesita 2*N.

// int oper(int a,int b)
// {
//   return a+b);
// }

struct nodo{
  int valor,abierto,cerrado;
  nodo(int a, int b , int c)
  {
    valor=a;
    abierto = b;
    cerrado = c;
  }
  nodo(){};
};


void build()
{
  int left,right,mini=INF;
  for(int i = n-1 ; i >= 0 ; --i)
    {
      left = (i<<1) ,right = (i<<1|1);
      mini = min(open[left], closed[right]);
      st[i] = st[left] + st[right] + mini;
      open[i] = open[left] + open[right] - mini;
      closed[i] = closed[left] + closed[right] - mini;
    }
  // st[i] = st[2*i] + st[2*i+1]
}

int query(int l , int r )
{
  nodo ansa(0,0,0), ansb(0,0,0);
  int mini;
  for(l += n , r += n  ;  l < r ; l>>=1 , r>>=1) 
    {
      mini = INF;
      if(l&1)
	{
	  mini = min(ansa.abierto,closed[l]);
	  ansa.valor += st[l] + mini;
	  ansa.abierto = ansa.abierto + open[l] - mini;
	  ansa.cerrado = ansa.cerrado + closed[l] - mini;
	  ++l;
	}
      if(r&1)
	{
	  --r;
	  mini = min(open[r],ansb.cerrado);
	  ansb.valor += st[r] + mini;
	  ansb.abierto = ansb.abierto + open[r] - mini;
	  ansb.cerrado = ansb.cerrado + closed[r] - mini;
	}
    }
  mini = min(ansa.abierto,ansb.cerrado);
  return (ansa.valor + ansb.valor + mini) * 2;
}

void init()
{
  memset(open, 0 ,sizeof open);
  memset(closed, 0 ,sizeof closed);
}

void printST()
{
  for(int i = 0 ; i < 2*n ; ++i)
    {
      cout << st[i] << " ";
    }
  cout << "\n";
  for(int i = 0 ; i < 2*n ; ++i)
    {
      cout << open[i] << " ";
    }
  cout << "\n";
  for(int i = 0 ; i < 2*n ; ++i)
    {
      cout << closed[i] << " ";
    }
  cout << "\n";  
}



int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  string pat;
  cin >> pat;
  n = pat.size();
  init();
  for(int i = 0 ; i < n; ++i) // los elementos ingresan al piso(hojas).
    {
      if(pat[i] == '(')
	open[i+n] = 1;
      else
	closed[i+n] = 1;
      st[i+n]  = 0;
    }
  build();
  // printST();
  int q; cin >> q;
  for(int i = 0 ;i < q ; ++i)
    {
      int l,r; cin >> l >> r;
      cout << query(l-1,r) << "\n";
    }
  return 0;
}
