#include <bits/stdc++.h>
#define MAXN 30 // E = alphabet size
using namespace std;
bool exist=0;
struct Trie
{
  struct Node
  {
    Node * childs[MAXN];
    int words,prefix,cnt;
    Node(){
      for(int i = 0 ; i < MAXN ; ++i)
	childs[i] = NULL;
      words = prefix = cnt = 0;
    }
  };
  Node * root;
  Trie()  { root = new Node(); }
  void insert(string st)
  {
    Node * cur  = root;
    for(char c : st)
      {
	++cur->prefix;
	if( !cur->childs[cnvt(c)] ) // The son is not here
	  cur->childs[cnvt(c)] = new Node();
	cur = cur->childs[cnvt(c)];
      }
    ++cur->words;
  }

  int findWords(string st, bool word) // return prefix or words.
  {
    Node * cur  = root;
    for(char c : st)
      {
	// cout << cur->prefix << "\n";
	if( !( cur->childs[cnvt(c)] ) )
	  return 0;
	cur = cur->childs[cnvt(c)];
      }
    if(word)
      return cur->words;
    return cur->prefix;
  }

  bool imLeaf(Node * &r)
  {
    for(int i = 0 ; i < MAXN ; ++i)
      {
	if(r->childs[i] != 0)
	  return 0;
      }
    return 1;
  }

  int loser(Node * &r,int niv)
  {
    if(imLeaf(r))
      {
	if(niv % 2 != 0) return 1;
	else {
	  exist=1;
	  return 2;
	}
      }
    if(niv % 2 != 0)
      {
	for(int i = 0 ; i < MAXN ; ++i)
	  {
	    if(r->childs[i]!=0)
	      if(loser(r->childs[i],niv+1) == 1)
		return 1;
	  }
	return 2;
      }
    else
      {
	for(int i = 0 ; i < MAXN ; ++i)
	  {
	    if(r->childs[i]!=0)
	      if(loser(r->childs[i],niv+1) == 2)
		return 2;
	  }
	return 1;
      }        
  }

  int winner(Node * &r,int niv)
  {
    if(imLeaf(r))
      {
	if(niv % 2 != 0) return 1;
	else {
	  exist=1;
	  return 2;
	}
      }
    if(niv % 2 == 0)
      {
	for(int i = 0 ; i < MAXN ; ++i)
	  {
	    if(r->childs[i]!=0)
	      if(winner(r->childs[i],niv+1) == 1)
		return 1;
	  }
	return 2;
      }
    else
      {
	for(int i = 0 ; i < MAXN ; ++i)
	  {
	    if(r->childs[i]!=0)
	      if(winner(r->childs[i],niv+1) == 2)
		return 2;
	  }
	return 1;
      }        
  }

  char cnvt(char c) // function that converts
  {
    return c-'a';
  }

  int winnerus()
  {
    return winner(root,0);
  }
  int loserus()
  {
    return loser(root,0);
  }
  
};



int main()
{
  ios_base::sync_with_stdio(0);
  Trie *t = new Trie();
  int n,k; cin >> n >> k;
  string aux;
  for(int i = 0 ; i < n ; ++i)
    {
      cin >> aux;
      t->insert(aux);
    }
  int win = t->winnerus();
  int loser  = t->loserus();
  if(win == 2)
    cout << "Second" << "\n";
  else
    {
      if(loser == 2)
	cout << "First\n";
      else
	{
	  if(k % 2 ==0)
	    cout << "Second\n";
	  else
	    cout << "First\n";
	}
    }
  return 0;
}
