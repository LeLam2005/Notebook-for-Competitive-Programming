template<typename T=int> struct Mat{
  vector<vector<T>> mat;
  int row, col;

  Mat(int r=0, int c=0):row(r), col(c), mat(r, vector<T>(c)){}
  Mat(const vector<vector<T>> _mat):mat(_mat), row(_mat.size()), col(_mat[0].size()){}
  Mat identity(int n){
    Mat x(n, n);
    while(n--) x.mat[n][n]=1;
    return x;
  }

  Mat operator*(const Mat& other){
    int Col=other.col;
    Mat ans(row, col);
    for(int i=0; i<row; ++i){
      for(int j=0; j<Col; ++j){
        for(int k=0; k<col; ++k){
          ans.mat[i][j]=add(ans.mat[i][j], mul(mat[i][k], other.mat[k][j]));
        }
      }
    }
    return ans;
  }

  Mat power(ll exp){
    Mat base=*this, ans=identity(row);
    for(; exp>0; exp>>=1, base=base*base){
      if(exp&1) ans=ans*base;
    }
    return ans;
  }
};
