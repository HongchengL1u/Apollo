#ifndef TRAJ_PROJECTION
#define TRAJ_PROJECTION
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;
bool traj_xy2sl (vector<vector<double>>& xy,vector<vector<double>>& ref,vector<vector<double>>& sl);
bool point_xy2sl (vector<double>& xy,vector<vector<double>>& ref,vector<double>& sl);
bool get_traj_slist(vector<vector<double>>& traj,vector<double>& s);
int get_nearest_point_index(vector<vector<double>>& traj,vector<double>& point);
int calculate_distance(vector<double>& a,vector<double>& b);

#endif