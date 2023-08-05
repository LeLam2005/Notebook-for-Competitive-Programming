const int MAXBIT=30; //or 60 for 1e18
struct BinaryTrie{
  struct Node{
    Node* child[2];
    //manage node data here
    Node(){
      child[0]=child[1]=NULL;
    }
  };

  Node* root;

  BinaryTrie(){
    root=new Node();
  }

  void add(const ll& x){
    Node* p=root;
    for(int i=MAXBIT; i>=0; --i){
      bool type=(x>>i&1);
      if(p->child[type]==NULL) p->child[type]=new Node();
      p=p->child[type];
    }
  }

  //Query function here
};
