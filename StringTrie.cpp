const int NEXT_SZ=1;
const int MIN_ALPHABET=-1;
struct StringTrie{
  struct Node{
    Node* child[NEXT_SZ];
    //manage node data here
    Node(){
      for(int i=0; i<NEXT_SZ; ++i) child[i]=NULL;
    }
  };

  Node* root;

  StringTrie(){
    root=new Node();
  }

  void add(const string& s){
    Node* p=root;
    for(auto c:s){
      int id=c-MIN_ALPHABET;
      if(p->child[id]==NULL) p->child[id]=new Node();
      p=p->child[id];
    }
  }

  //Query function here
};
