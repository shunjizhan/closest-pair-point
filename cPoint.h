#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
  double x;
  double y;

  Point() {
    this->x = 0;
    this->y = 0;
  }

  Point(double x, double  y) {
    this->x = x;
    this->y = y;
  }

  void print() {
    cout << "(" << x << ", " << y << ")" << endl;
  }
};

class cPoints {
public:
  double n;
  vector<Point> allPoints;

  cPoints(double n) {
    this->n = n;
  }

  void printPoints() {
    for (vector<Point>::iterator it = begin (allPoints); it != end (allPoints); ++it) {
      it -> print();
    }
    cout << "n = " << n << endl;
  }
  
  void add(Point p) {
    allPoints.push_back(p);
  }

  void add(double x, double y) {
    allPoints.push_back(Point(x, y));
  }

  double getDistance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) + (p1.y - p2.y));
  }

  void bruteForce() {
    double comparison = 0;
    Point temp1, temp2;
    Point p1;
    Point p2;
    double distance;
    double minDistance = 999999999.9;

    for(vector<Point>::iterator it = allPoints.begin(); it != allPoints.end(); ++it) {
      temp1 = *it;
      for(vector<Point>::iterator it2 = allPoints.begin(); it2 != allPoints.end(); ++it2) {
        temp2 = *it2;
        distance = getDistance(temp1, temp2);
        comparison++;
        if (distance < minDistance && distance != 0) {
          minDistance = distance;
          p1 = temp1;
          p2 = temp2;
        }
      }
    }

    cout << "closest points: " << endl;
    cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << endl;
    cout << "comparisons: " << endl;
    cout << comparison << endl;
  }

  vector<double> DAC() {
    // x0 y0 x1 y1 comparisons 
    return DAC(allPoints);
  }

  vector<double> DAC(vector<Point> points) {
    vector<double> result;
    result.push_back(0.0);
    result.push_back(0.0);
    result.push_back(0.0);
    result.push_back(0.0);
    result.push_back(-999999999.9);

    if (points.size() < 2) { 
      cout << "error!"; 
      return result;
    } else if (points.size() == 2) { 
      result.clear(); 
      result.push_back(points.at(0).x);
      result.push_back(points.at(0).y);
      result.push_back(points.at(1).x);
      result.push_back(points.at(1).y);
      result.push_back(0);
      return result;
    }

    double comparison = 0;
    Point temp1, temp2;
    double x0, y0, x1, y1;
    double distance;
    double minDistance = 999999999.9;

    return result;
  }

};








