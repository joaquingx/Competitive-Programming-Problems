#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
  vector<int> bit; // binary indexed tree
  int n;

  void init(int n) {
    this->n = n;
    bit.assign(n, 0);
  }
  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r+1)) - 1) // saltando hacia atras entre rangos
      {
	// cout << "r : "<<r << "\n";
	ret += bit[r];
      }
    return ret;
  }
  void add(int idx, int delta) { // saltando hacia adelante(no necesariamente entre rangos!).
    for (; idx < n; idx = idx | (idx+1))
      bit[idx] += delta;
  }
  int sum(int l, int r) {
    return sum(r) - sum(l-1);
  }
  void init(vector<int> a) {
    init(a.size());
    for (size_t i = 0; i < a.size(); i++)
      add(i, a[i]);
  }
};



int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  FenwickTree rpta;
  vector<int> aux,acciones,posis;
  int n,q,x,l; cin >> n >> q;
  int ptr=0;
  rpta.init(n);aux.assign(n,0);posis.assign(n,-1);
  for(int i = 0 ; i < q ; ++i)
    {
      cin >> x >> l;
      switch(x)
	{
	case 1:
	  rpta.add(l-1,1);
	  ++aux[l-1];
	  acciones.push_back(l-1);
	  break;
	case 2:
	  rpta.add(l-1,-aux[l-1]);
	  aux[l-1] = 0;
	  posis[l-1] = acciones.size()-1;
	  break;
	case 3:
	  for(int j = ptr ; j < l ; ++j)
	    {
	      int accion = acciones[j];
	      if(j > posis[accion])
		{
		  rpta.add(accion,-1);
		  --aux[accion];
		}
	      ++ptr;
	    }
	  // ++ptr;
	  break;
	}
      // for(int j = 0 ;j < acciones.size() ; ++j)
      // 	cout << acciones[j]+1 << " " ;
      // cout << "\n";
      cout << rpta.sum(n-1) << "\n";
    }
}
