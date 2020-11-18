#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>

using std::vector;
using std::string;
using std::pair;
using std::cout;

struct point {
    int x;
    int y;
};

double distance(point a, point b) {
    double p = abs(a.x - b.x), q = abs(a.y - b.y);
    int dd = 1;
    const int d = 1000;
    if(p > d && q > d) {
        p /= d;
        q /= d;
        dd = d;
    }
    return dd*sqrt(p*p + q*q);
}

bool XIsLess(point a, point b) {
    return a.x < b.x;
}

bool YIsLess(point a, point b) {
    return (a.y < b.y) or (a.y == b.y and a.x < b.x);
}

double naive_min_dist(vector<point> &points, int left, int right) {
    int i, j, k=0;
    double min;
    vector<double> d((right - left + 1)*(right - left)/2);
    for(i = left; i <= right; ++i)
        for(j = i+1; j <= right; ++j)
            d[k++] = distance(points[i], points[j]);
    min = d[0];
    for(i=1; i < d.size(); ++i)
        if(d[i] < min)
            min = d[i];
    return min;
}

double min_dist_strip(vector<point> &y, double d) {
    if(y.size() < 2)
        return d;
    double dist;
    // proven fact for rectange 2d x d:
    // for any point exist no more than 8 points
    // such that distance less than d
    for(size_t i = 0; i < y.size(); ++i) {
        for(size_t j = i+1; j < y.size() && y[j].y - y[i].y < d; ++j) {
            dist = distance(y[i], y[j]);
            if(dist < d)
                d = dist;
        }
    }
    return d;
}

double r_min_dist(vector<point> &points_by_x, vector<point> &points_by_y,
    int left, int right)
{
    if(right - left < 3)
        return naive_min_dist(points_by_x, left, right);
    
    int mid = (left+right)/2; // index of vertical line
    int mid_x = points_by_x[mid].x; // x-coordinate of vertical line
    double min_l, min_r, min_strip, min;
    size_t i;
    vector<point> pyl, pyr;
    for(i=0; i<points_by_y.size(); ++i)
        if(points_by_y[i].x <= mid_x)
            pyl.push_back(points_by_y[i]);
        else if(points_by_y[i].x >= mid_x)
            pyr.push_back(points_by_y[i]);

    min_l = r_min_dist(points_by_x, pyl, left, mid);
    min_r = r_min_dist(points_by_x, pyr, mid, right);

    //std::cout << "[" << left << ", " << mid << "] " << min_l << " - ";
    //std::cout << "[" << mid+1 << ", " << right << "] " << min_r;
    //std::cout << std::endl;
    min = std::min(min_l, min_r);
    // find strip_min inside strip where x in [mid_x - min; mid_x + min]
    // select points inside min-strip sorted by y
    vector<point> ystrip;
    for(i = 0; i < points_by_y.size(); ++i)
        if(abs(mid_x - points_by_y[i].x) <= min)
            ystrip.push_back(points_by_y[i]);

    min_strip = min_dist_strip(ystrip, min);

    return std::min(min, min_strip);
}

double min_dist(vector<point> &points_by_x, vector<point> &points_by_y) {
    // sort by x coordinates
    sort(points_by_x.begin(), points_by_x.end(), XIsLess);
    // sort by y coordinates
    sort(points_by_y.begin(), points_by_y.end(), YIsLess);
    // recursive find the minimum distance
    return r_min_dist(points_by_x, points_by_y, 0, points_by_x.size() - 1);
}

int main() {
    size_t n;
    // read number of points
    std::cin >> n;
    // read n points
    vector<point> points_by_x(n); // sorted by x
    vector<point> points_by_y(n); // sorted by y
    for (size_t i = 0; i < n; i++) {
        std::cin >> points_by_x[i].x >> points_by_x[i].y;
        points_by_y[i].x = points_by_x[i].x;
        points_by_y[i].y = points_by_x[i].y;
    }

    std::cout << std::fixed;
    std::cout << std::setprecision(9) << min_dist(points_by_x, points_by_y) << "\n";
}
