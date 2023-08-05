const double PI=acos(-1);

double to_radians(double x){
  return x*PI/180.0;
} //sin in c++ using radians, so if we want to calculate sin(x) with x in degrees, we have to transform x to radians

double to_degree(double x){
  return x*180.0/PI;
}

struct Point{
  int x, y;
  Point(int x=0, int y=0):x(x), y(y){}
  friend istream& operator>>(istream& in, Point& cur){ return in>>cur.x>>cur.y; }
  friend ostream& operator<<(ostream& out, const Point& cur){ return out<<cur.x<<' '<<cur.y; }
  Point& operator+=(const Point& other){ x+=other.x, y+=other.y; return *this; }
  Point& operator-=(const Point& other){ x-=other.x, y-=other.y; return *this; }
  Point& operator*=(const int& other){ x*=other, y*=other; return *this; }
  Point& operator/=(const int& other){ x/=other, y/=other; return *this;}

  Point operator+(const Point& other){ return *this+=other; }
  Point operator-(const Point& other){ return *this-=other; }
  Point operator*(const int& other){ return *this*=other; }
  Point operator/(const int& other){ return *this/=other; }

  int norm(){ return x*x+y*y; }
  double length(){ return sqrt(norm()); }
};

//compute AB.AC
int dot(const Point& a, const Point& b, const Point& c){
  return (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);
}

//compute ABxAC
int cross(const Point& a, const Point& b, const Point& c){
  return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

//compute distance from line AB to point C
double LineToPoint(Point a, Point b, Point c){
  return abs(cross(a, b, c))/(a-b).length();
}

int type(int x){
  if(x>0) return 1; //ccw
  if(x<0) return -1; //cw
  if(x==0) return 0; //collinear
  assert(false); //never happen
}

bool onSegment(const Point& a, const Point& b, const Point& c){
  //segment AB, point c
  return (!type(cross(c, a, b)) and dot(c, a, b)<=0);
}

bool intersect(const Point& a, const Point& b, const Point& c, const Point& d){
  if(onSegment(a, b, c) or onSegment(a, b, d) or onSegment(c, d, a) or onSegment(c, d, b)) return true;
  return (type(cross(a, b, c))*type(cross(a, b, d))<0 and type(cross(c, d, a))*type(cross(c, d, b))<0);
}

//Ray casting algorithm/Jordan curve theorem
//Pick theorem : lattice points area
/*
Denote S is the area of the polygon, I is the number of lattice points inside the polygon, B is the number of lattice points lay on its sides
Formula : S=I+(B/2)-1
  => I=1+S-(B/2)
  => B=2*(S+1-I)
*/
