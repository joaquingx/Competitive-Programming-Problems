#include <bits/stdc++.h>
using namespace std;
typedef int treetp;

struct Node {
  Node * childs[2];
  Node * parent;
  treetp data;
  int onmyhand[2];
  Node(Node * nparent, Node * left , Node * right, treetp ndata) 
  {  parent  = nparent, childs[0] = left , childs[1] = right , data = ndata, onmyhand[0] = 0 , onmyhand[1] = 0; }  ;
};

Node * root;

inline int giveme(Node * &x)
{
  return x->onmyhand[0] + x->onmyhand[1] + 1;
}

void rotate(Node * & x) // x = node to splay
{
  // y = parent(x) , z = parent(parent(x)) = grandpa(x)
  Node * y = x->parent;   
  Node * z = y->parent;
  bool yside = !(y->childs[0] == x);
  y->onmyhand[yside]=0;
  if(x->childs[!yside])
    {
      y->onmyhand[yside] +=giveme(x->childs[!yside]); // modification 1 
      y->childs[yside] = x->childs[!yside];
      x->childs[!yside]->parent = y;
    }
  else
    {
      y->childs[yside] = NULL;
    }
  x->onmyhand[!yside] = giveme(y); // 3
  x->childs[!yside] = y;
  if(z)
    {
      bool zside = !(z->childs[0] == y);
      z->childs[zside] = x;
      x->parent = z;
    }
  else x->parent = NULL;
  y->parent = x;
}

void Splay(Node * & x)
{
  while(x->parent)
  {
    Node * y = x->parent;
    Node * z = y->parent;
    bool yside = !(y->childs[0] == x);
    if(!z) // simple rotation
      {
	rotate(x);
	break;
      }
    bool zside = !(z->childs[0] == y);
    // double rotations
    if(yside == zside) //zig zig
      rotate(y) , rotate(x);
    else // zig zag
      rotate(x) , rotate(x);
  }
  root = x; // maybe unneccesary
}

Node * Find(treetp key, Node * & r)
{
  bool side;
  if(r==0 && r == root)  return 0;
  if(r->data==key && r == root) return r;

  while(true)
    {
      side = (r->data < key);
      if(r->data == key)  break;
      if(r->childs[side]) r = r->childs[side];
      else break;	
    }
  
  Splay(r);
  if(r->data == key) return r;
  else return NULL;
}


bool Insert(treetp key)
{
  if(!root)
    {
      root = new Node(NULL,NULL,NULL,key) ;
      return 1;
    }
  Node * r = root;
  bool insert=0;
  while(!insert)
    {
      if(r->data == key){
	Splay(r);
	return 0;
      }
      bool side = (r->data < key);
      if(r->childs[side]) r = r->childs[side];
      else
	r->childs[side] = new Node(r,NULL,NULL,key) , r = r->childs[side] , insert = 1;      
    }
  Splay(r);
  return 0;
}

bool Erase(treetp key) 
{
  Node * r  = Find(key,root); 
  if(!r) return 0;
  Node * left = r->childs[0];
  if(!left)
    {
      root = r->childs[1];
      if(root) root->parent = NULL;
      free(r);
      return 1;
    }
  while(left->childs[1]) left = left->childs[1]; // we go all right

  root = r->childs[0];
  root->parent = NULL;
  Splay(left);
  if(r->childs[1])
    {
      root->childs[1] =r->childs[1];
      r->childs[1]->parent = root;
    }
  free(r);
  return 1;
}

int count(int key)
{
  int rpta=0;
  Node * r = root;
  if(r==0) return 0;
  while(true)
    {
      bool side  = (r->data <= key );
      if(side == 1)
	{
	  if(r->data != key)
	    rpta+=r->onmyhand[0]+1;
	  else
	    rpta += r->onmyhand[0];
	}
      if(r->childs[side] == 0) break;
      r = r->childs[side];      
    }
  Splay(r);
  return rpta;
}

inline int kesimo (int ks)
{
  Node * r  = root;
  if(r==0)return -1;
  while(true)
    {
      int my = r->onmyhand[0]+1;
      if(my == ks)
	{
	  Splay(r);
	  return r->data;
	}
      bool side = !(my>=ks);
      if(r->childs[side] == 0) break;
      if(side == 1) ks -= my;
      r = r->childs[side];
    }
  Splay(r);
  return -1;
}

void Inorder(Node * r)
{
  if(r)
    {
      Inorder(r->childs[0]);
      printf(" Nodo : %d  con %d left y %d right\n",r->data,r->onmyhand[0],r->onmyhand[1]); // problems with typedef
      Inorder(r->childs[1]);
    }
  // printf("\n");
}


int main()
{
  ios_base::sync_with_stdio(0);
  char k;
  int n,c,rpta; scanf("%d",&n);
  while(n--)
    {
      scanf(" %c %d",&k,&c);
      if(k == 'I')
	Insert(c);
      if(k == 'D')
	Erase(c);
      if (k== 'C')
	{
	  printf("%d\n",count(c));
	}
      if(k=='K')
      	{
	  rpta = kesimo(c);
	  if(rpta == -1)
	    puts("invalid");
	  else
	    printf("%d\n",rpta);
      	}
    }
  return 0;
}
