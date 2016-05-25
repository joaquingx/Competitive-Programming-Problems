#include <bits/stdc++.h>
using namespace std;
typedef long long ENTERO;
#define MAXN 51
#define PATO int(1e4+10)
#define INF ENTERO(2*1e12)
struct edge{ENTERO to, length;};
typedef vector< vector< edge > > Adjacency;
typedef vector< vector<int> > Graph;

vector< vector<int > > Dist;
Adjacency List;
vector<ENTERO> who;
char Matrix[MAXN][MAXN];
bool vis[MAXN*MAXN];
Graph G;
int r,c,cnt;
string pat;

// Dijkstra con Colas de Prioridad O( (n + m) * logn )
vector<ENTERO> NiceDijkstra(Adjacency &Grafo, ENTERO source)
{
  vector<ENTERO> dist(Grafo.size(),INF); // VECTOR DE DISTANCIAS.
  dist[source] = 0; // Init de distancias.
  set< pair <ENTERO, ENTERO > > now; // distancia , indice
  now.insert( {0,source} ); // Cola de Prioridad que elige el vertice siguiente a escoger.
  while(!(now.empty()))
    {
      ENTERO where = now.begin()->second; // Escoge el nodo mas conveniente.
      now.erase(now.begin());
      for(auto edge : Grafo[where])
	{
	  if(dist[edge.to] > dist[where] + edge.length) // si existe una arista mas conveniente go.
	    {
	      now.erase( {dist[edge.to],edge.to} ); // borramos el que existia.
	      dist[edge.to] = dist[where] + edge.length ; //actualizamos vector de dist.
	      now.insert( { dist[edge.to] , edge.to  } ); // actualizamos priority queue.
	    }
	}
    }
  return dist;
}



inline void bfs(int source)
{
  queue<int> cola; cola.push(source);
  Dist[source][source] = 0;
  while(! ( cola.empty()) )
    {
      //++dist;
      int u = cola.front(); cola.pop();
      vis[u] = 1;
      for(int i  = 0 ; i < G[u].size() ; ++i)
	{
	  int v = G[u][i];
	  if(vis[v] != 1)
	    {
	      Dist[source][v] = Dist[source][u] + 1;
	      cola.push(v);
	    }
	}
    }
}

bool cmp(int i1,int j1, int i2 , int j2,int w,int cnt)
{
  int conti=cnt,aux=cnt;
  if(w ==1) conti--;
  if(w==2) conti++;
  if(w==3) conti+=c;
  if(w==4) conti-=c;
  if(i2 < r and i2 >= 0 and j2 >= 0 and j2 < c)
    {
      while(Matrix[i1][j1] == Matrix[i2][j2])
	{
	  if(i2 >= r or i2 < 0 or j2 < 0 or j2 >= c)
	    return 0;
	  if(w == 1)
	    {
	      --j2;
	      --conti;
	    }
	  if(w == 2)
	    {
	      ++j2;
	      ++conti;
	    }
	  if(w == 3)
	    {
	      ++i2;
	      conti+=c;
	    }
	  if(w == 4)
	    {
	      --i2;
	      conti-=c;
	    }
	}
      if(i2 >= r or i2 < 0 or j2 < 0 or j2 >= c)
	return 0;
      if(Matrix[i1][j1] != Matrix[i2][j2])
	{
	  G[aux].push_back(conti);
	  return 1;
	}
      return 0;
    } 
  return 0;
}

int main()
{
  string pri;
  ios_base::sync_with_stdio(0);
  cnt=0;
  G.resize(MAXN*MAXN);
  Dist.resize(MAXN*MAXN);
  for(int i = 0 ; i < Dist.size() ; ++i)
    Dist[i].resize(MAXN*MAXN,-1);
  cin >> r >> c;
  for(int i = 0 ; i < r ; ++i)
    for(int j = 0 ; j < c ; ++j)
      cin >> Matrix[i][j];
  cin >> pri;
  pat += Matrix[0][0];
  pat += pri;
  pat += "*";
  for(int i = 0 ; i < r ; ++i) // armando el grafo
    for(int j = 0 ; j < c ; ++j)
      {
	cmp(i,j,i,j-1,1,cnt);
	cmp(i,j,i,j+1,2,cnt);
	cmp(i,j,i+1,j,3,cnt);
	cmp(i,j,i-1,j,4,cnt);
	++cnt;
      }
  for(int i = 0 ; i < r*c ; ++i)
    {
      memset(vis,0,sizeof vis);
      bfs(i);
      // cout << i << ":\n";
      // for(int j = 0 ; j < r*c ; ++j)
      // 	cout << Dist[i][j] << " ";
      // cout << "\n";
    }
  List.resize(r*c*PATO+1);
  for(int i = 0 ; i < r*c ; ++i)
    {
      if(Matrix[i/c][i%c] == pat[0])
	List[r*c+1].push_back({i,0});
    }
  vector< vector<int> >  mine(MAXN);
  for(int i = 0; i < pat.size(); ++i)
    {
      for(int j = 0 ; j < r*c ; ++j)
	{
	  if(Matrix[j/c][j%c] == pat[i])
	    mine[i].push_back(j);
	}
    }
  // cout << pat << "\n";
  for(int j= 0 ; j < pat.size()-1 ; ++j)
    {
      for(int f = 0 ; f < mine[j].size() ; ++f)
	{
	  for(int k = 0 ; k < mine[j+1].size() ; ++k)
	    {
	      if(Dist[mine[j][f]][mine[j+1][k]] != -1)
		List[mine[j][f]].push_back({mine[j+1][k],Dist[mine[j][f]][mine[j+1][k]]});
	      else
		List[mine[j][f]].push_back({mine[j+1][k],INF});
	      // List[mine[j][k]].push_back({mine[i+1][k],Dist[mine[i][j],mine[i+1][k]]});
	    }
	}
      
    }
  // for(int i = 0 ; i < r*c ; ++i)
  //   {
  //     cout << Matrix[i/c][i%c] << ":\n";
  //     for(int j = 0 ; j < List[i].size() ; ++j)
  // 	cout << Matrix[List[i][j].to/c][List[i][j].to % c] << " y "  << List[i][j].length << "  "  ;
  //     cout << "\n";
  //   }
  vector<ENTERO> distancias = NiceDijkstra(List,r*c+1);
  ENTERO mini = INF;
  for(int i = 0 ; i < r*c+2 ; ++i)
    {
      if(Matrix[i/c][i%c] == '*')
	mini = min(distancias[i],mini);
    }
  cout << mini+pri.size() + 1 << "\n";
  // for(int i = 0 ; i < r*c+2 ; ++i)
  //   {
  //     // cout << Matrix[i/c][i%c] << ":\n";
  //   }
  // cout << "\n";
  // for(int i = 0 ; i < r*c ; ++i)
  //   {
  //     cout << i << " " << Matrix[i/c][i%c] << ": \n";
  // 	for(int j = 0 ; j < G[i].size() ; ++j)
  // 	  cout << G[i][j]  << " ";
  //     cout << "\n";
  //   }
  return 0;
}
