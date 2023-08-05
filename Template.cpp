#include<bits/stdc++.h>

using namespace std;

#define TASKFILE "a"
#define range(v) begin(v), end(v)
#define compact(v) v.erase(unique(range(v)), end(v))
#define fir first
#define sec second
#define len(x) (int)(x).size()
#define left Le
#define right Lam
#define div Divvvv
#define next Nextttt
#define prev Prevvvv
#define BIT(x, i) ((x)>>(i)&1)
#define MASK(x) (1LL<<(x))

template<class T> bool maximize(T& a, const T& b){
  if(a<b){
    a=b;
    return true;
  } else return false;
}

template<class T> bool minimize(T& a, const T& b){
  if(a>b){
    a=b;
    return true;
  } else return false;
}

typedef long long ll;
typedef unsigned long long ull;

void Zero_OP(){

}

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);

  if(fopen(TASKFILE".inp", "r")){
    freopen(TASKFILE".inp", "r", stdin);
    freopen(TASKFILE".out", "w", stdout);
  }

  int TC=1; cin>>TC;
  while(TC--) Zero_OP();

  return 0;
}
