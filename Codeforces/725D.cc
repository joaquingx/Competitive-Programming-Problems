#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll INF = (1ull << 60) + 123;



struct FenwickTree {
  vector<ll> bit; // binary indexed tree
  int n;
  
  inline ll oper(ll a, ll b) {
    a += b;
    if (a > INF) a = INF;
    return a;
  }
  
  void init(int n) {
    this->n = n;
    bit.assign(n, 0);
  }
  ll sum(int r) {
    ll ret = 0;
    for (; r >= 0; r = (r & (r+1)) - 1) // saltando hacia atras entre rangos
      {
	// cout << "r : "<<r << "\n";
	ret = oper(ret,bit[r]);
      }
    return ret;
  }
  void add(int idx, ll delta) { // saltando hacia adelante(no necesariamente entre rangos!).
    for (; idx < n; idx = idx | (idx+1))
      bit[idx] = oper(bit[idx],delta);
  }
  int sum(int l, int r) {
    return sum(r) - sum(l-1);
  }
  void init(vector<ll> a) {
    init(a.size());
    for (size_t i = 0; i < a.size(); i++)
      add(i, a[i]);
  }
};


FenwickTree bitcount,bitacum;
vector<ll> puestos,vete;
vector<pair < ll , ll > > a;
vector<int> toid;


ll bs(int a , int b, ll key)
{
  int ini = a, fin = b , med,res=-1;
  while(fin - ini > 0)
    {
      med = (ini + fin)/2;
      // cout << "Acum : "<<bitacum.sum(med) << "\n";
      if(bitacum.sum(med) <= key)
	{
	  res = med;
	  ini = med+1;
	}
      else
	fin = med;
    }
  // cout << "Final : "<<bitacum.sum(ini) << "\n";
  // cout << "\n";
  // if(bitacum.sum(med))
  return bitcount.sum(res);
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n; cin >> n;
  puestos.resize(n); vete.resize(n); a.resize(n); toid.resize(n);
  ll minescore,minew;
  cin >> minescore >> minew;
  minew = minew - minescore;
  for(int i = 1 ; i < n; ++i)
    {
      cin >> a[i].first >> a[i].second;
      a[i].second = a[i].second  - a[i].first + 1;
      puestos[i] = i;
      vete[i] = i;
    }
  sort(puestos.begin(), puestos.end() , [&] (int i , int j ) { return a[i].first > a[j].first ;});
  sort(vete.begin() , vete.end() , [&] (int i , int j ) { return a[i].second < a[j].second ;} );

  for(int i = 0 ;i < n; ++i)
    {
      toid[vete[i]] = i ;
      // cout << vete[i] << " : " << toid[vete[i]] << "\n";
    }
  bitacum.init(n);
  bitcount.init(n);
  int idx1,idx2,id;
  ll rpta=INF;
  for(int i = 0 ;i < n; ++i)
    {
      idx1 = puestos[i];
      idx2 = vete[i];
      if(a[idx1].first <= minescore)
	{
	  ll cuanto = minescore - a[idx1].first;
	  // cout << cuanto << "    ";
	  // cout << bs(0,n,cuanto) << "\n";
	  rpta = min(rpta , i - bs(0,n,cuanto)+1);	  
	}
      // cout << "puestos: " << puestos[i] << " ";
      id = toid[idx1];
      // cout << "id: " << id << " " ;
      // cout << "costos : "<< a[idx1].second << "\n";
      bitacum.add(id,a[idx1].second);
      bitcount.add(id,1);
    }
  ll  candel = bs(0,n,minescore) ;
  rpta = min(rpta, n  - candel+1);
  cout << rpta << "\n";
  return 0;
}
