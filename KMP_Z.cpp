vector<int> prefix_function(const string& s){
  int n=len(s);
  vector<int> pi(n);
  for(int i=1, j=0; i<n; ++i){
    while(j>0 and s[i]!=s[j]){
      j=pi[j-1];
    }
    if(s[i]==s[j]) ++j;
    pi[i]=j;
  }
  return pi;
}

vector<int> z_function(const string& s){
  int n=len(s);
  vector<int> z(n);
  for(int i=1, l=0, r=0; i<n; ++i){
    z[i]=max(0, min(r-i, z[i-l]));
    while(i+z[i]<n and s[z[i]]==s[i+z[i]]){
      ++z[i];
    }
    if(i+z[i]>r){
      l=i, r=i+z[i];
    }
  }
  return z;
}
