string s;
int n, sa[N], tmpsa[N], tmpra[N], ra[N], lcp[N];

void countingSort(int k){
  int max_sz=max(300, n);
  vector<int> cnt(max_sz);
  for(int i=0; i<n; ++i) ++cnt[i+k<n?ra[i+k]:0];
  for(int i=0, sum=0; i<max_sz; ++i){
    int t=cnt[i]; cnt[i]=sum, sum+=t;
  }
  for(int i=0; i<n; ++i) tmpsa[cnt[sa[i]+k<n?ra[sa[i]+k]:0]++]=sa[i];
  copy(tmpsa, tmpsa+n, sa);
}

void buildSA(){
  iota(sa, sa+n, 0); copy(s.begin(), s.end(), ra);
  for(int k=1; k<n; k<<=1){
    countingSort(k); countingSort(0);
    fill(tmpra, tmpra+n, 0);
    int r=0; tmpra[sa[0]]=r;
    for(int i=1; i<n; ++i){
      tmpra[sa[i]]=((ra[sa[i]]==ra[sa[i-1]]) and (ra[sa[i]+k]==ra[sa[i-1]+k])?r:++r);
    }
    copy(tmpra, tmpra+n, ra);
    if(ra[sa[n-1]]==n-1) break;
  }
}

void buildLCP(){
  for(int i=0; i<n; ++i) ra[sa[i]]=i;
  for(int i=0, k=0; i<n; ++i) if(ra[i]!=(n-1)){
    int j=sa[ra[i]+1];
    while(s[i+k]==s[j+k]) ++k;
    lcp[ra[i]]=k;
    if(k) --k;
  }
}
