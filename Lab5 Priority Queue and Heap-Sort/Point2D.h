/* Point2D.h
 * demonstrates a class to represent points with a comparator class.
 * 
 * Define two classes.
 * Point2D:
 *    object represent a point on two dimensional plane.
 * LexCompare:
 *    contains a member function to perform comparisons
 *    between Point2D objects.
 */

#include <string>
#include <sstream>
#include <cmath>

class Point2D {				// example class
private:
	double x;  // variables represent coordinates
	double y;
public:
  	Point2D(double xCoord=0, double yCoord=0)  // constructor
		{ x = xCoord; y = yCoord; }
	// access functions
	double getX() const { return x; }
	double getY() const { return y; }
	std::string print() const {
		// + operator is not supported for C++ strings
		// std::string s = "(" + x + "," + y + ")";
		// implement string construction using ostringstream
		std::ostringstream s;
		s << "(" << x << "," << y << ")";
		return s.str();
		}
	double originDist() const {
		return sqrt((x * x) + (y * y));
	}
};

// BK: output operator
ostream& operator<<(ostream &out, const Point2D &p) {
	out << p.print();
	return out;
}

// Comparator class
// function (p1,p2) returns
//    true if p1 is less than p2
//    false otherwise.

class LexCompare {	// implements lexicographic comparison of Point2D objects
					// where the coordinates are considered in left-to-right order
					// for (x, y), first compare x, and then compare y
public:
  bool operator()(const Point2D& p1, const Point2D& p2) const {
    if (p1.getX() == p2.getX()) 	 // first compare x coordinates
      return p1.getY() < p2.getY();	 // if x coordinates are same,
									 // the smaller y comes first
    else
	  return p1.getX() < p2.getX();  // otherwise, smaller x comes first
  }
};

class DistCompare {	// implements distance from origin comparison of Point2D objects
					// where the coordinates are considered in left-to-right order
					// for (x, y), first compare x, and then compare y
public:
	bool operator()(const Point2D& p1, const Point2D& p2) const {
		return (p1.originDist() < p2.originDist()); 	 // returns true if the distance from the origin for p1 is less than distance from the origin of p2
	}
};
