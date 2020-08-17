/*
 * helpers.cpp
 *
 *  Created on: 26 Jul 2020
 *      Author: Carissa
 */

#include "helpers.h"

#define deb(x) cout << #x << " " << endl; //DEBUGGING TOOL 

#define max(a, b) (((a) > (b)) ? (a) : (b))


using Eigen::MatrixXd;
using Eigen::VectorXd;





string hasData(string s) {
  auto found_null = s.find("null");
  auto b1 = s.find_first_of("[");
  auto b2 = s.find_first_of("}");
  if (found_null != string::npos) {
    return "";
  } else if (b1 != string::npos && b2 != string::npos) {
    return s.substr(b1, b2 - b1 + 2);
  }
  return "";
}


constexpr double pi() { return M_PI; }
double deg2rad(double x) { return x * pi() / 180; }
double rad2deg(double x) { return x * 180 / pi(); }

double mph2ms(double x) { return x / 2.2369; }
double ms2mph(double x) { return x * 2.2369; }

double norm(double x, double y) {
	return sqrt(x * x + y * y);
}

double norm(double x, double y, double z) {
	return sqrt(x * x + y * y + z * z);
}

// Calculate magnitude of normal and tangential components 
double magnitude(double x, double y) {
  double magnitude = sqrt(pow(x, 2) + pow(y, 2));
  return magnitude;
}


double distance(double x1, double y1, double x2, double y2)
{
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int Path::size(){
  return this->pts_x.size();
}

Path Path::previous_path_from_json(const nlohmann::json &j) {

  auto prev_path_x = j[1]["previous_path_x"];
  auto prev_path_y = j[1]["previous_path_y"];

  Path path;
  for(int i = 0; i < prev_path_x.size(); i++) {
    path.pts_x.push_back(prev_path_x[i]);
    path.pts_y.push_back(prev_path_y[i]);
  }

  path.end_s = j[1]["end_path_s"];
  path.end_d = j[1]["end_path_d"];

  return path;
}


int ClosestWaypoint(double x, double y, const vector<double> &maps_x, const vector<double> &maps_y) {

  double closestLen = 100000; //large number
  int closestWaypoint = 0;

  for(int i = 0; i < maps_x.size(); i++) {
    double map_x = maps_x[i];
    double map_y = maps_y[i];
    double dist = distance(x, y, map_x, map_y);
    if(dist < closestLen) {
      closestLen = dist;
      closestWaypoint = i;
    }

  }

  return closestWaypoint;

}


