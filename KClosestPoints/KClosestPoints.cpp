#include <cmath>

struct Point {
  double x;
  double y;
};

//This struct is used when calulated and saving distances.
// It enables us to map a distance to a point, without losing the 
// point or modifying the point structure.    
struct DistanceToOrigin {
    double distance;
    Point * point;
};
 
//the stl comparator function, returns the smaller of the two as first in list    
static bool compare_shortestDistanceFirst(const DistanceToOrigin first,
                                          const DistanceToOrigin second) {
    if (first.distance <= second.Distance) {
        return true;    
    }
    return false;
}

/* Returns the closes k points in the provided list. Does this my analyzing the
 distance from each point to the origin(0,0), then sorting them to find the closest
 points. Uses the stl sort and stl list. This algorithm has a Big-O of O(n). It only
traverses through the list provided once. */
static Point * closestk( Point * myList, int n, int k ) {
    std::list<DistanceToOrigin> distanceToOrigin;
    
    for ( int i = 0; i < n; i++) {
        //calculate the distance formula from 0 and add to list
        //duistance formula a^2 + b^2 = c^2
        DistanceToOrigin disToOrg;
        disToOrg.distance = sqrt(pow(myList[i].x, 2), pow(myList[i].y, 2));
        disToOrg.point = &myList[i];
        
        distanceToOrigin.push_back(disToOrg);
    }
    
    //sort list. We use the standard comparator becasue it uses a quicksort
    distanceToOrigin.sort(compare_shortestDistanceFirst);
    
    //take the first ke elements and return them.
    Point returnList[k];
    for (int i = 0; i < k; i++) {
        returnList[i].x = distanceToOrigin.front().x;
        returnList[i].y = distanceToOrigin.front().y;
        distanceToOrigin.pop_front();        
    }
    
    return returnList;
}