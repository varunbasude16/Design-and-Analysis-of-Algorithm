#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cfloat>
using namespace std;

struct Point {
    double x, y;
};

double distance(Point a, Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double bruteforce(vector<Point> &points,int l, int h){
    double mindist=DBL_MAX;
    for(int i=l;i<=h;i++)
        for(int j=i+1;j<=h;j++)
            mindist=min(mindist,distance(points[i],points[j]));
    return mindist;
}
double stripclosest(vector<Point> &strip, double d) {
    sort(strip.begin(),strip.end(),[](Point a, Point b){return a.y<b.y;});
    double mindst=d;
    for(int i=0;i<strip.size();i++)
        for(int j=i+1;j<strip.size();j++)
            if((strip[j].y - strip[i].y)<mindst)
                mindst=min(mindst,distance(strip[i],strip[j]));
    return mindst;
}

double closestUtil(vector<Point> &points,int l, int h){
        if(h-l<=2) 
        return bruteforce(points,l,h);
        double mid=l+(h-l)/2;
        Point midPoint=points[mid];
        double dl=closestUtil(points,l,mid);
        double dr=closestUtil(points,mid+1,h);
        double d=min(dl,dr);
        vector<Point> strip;
        for(int i=l;i<=h;i++)
            if(abs(points[i].x -midPoint.x)<d)
                strip.push_back(points[i]);
        return min(d,stripclosest(strip,d));

}
bool compareX(Point a, Point b) {
    return a.x < b.x;
}
double closest(vector<Point> &points){
    sort(points.begin(),points.end(),compareX);
    return closestUtil(points,0,points.size()-1);
}
int main() {
    vector<Point> points={{0, 2},{1, 5},{2, 2},{6, 3},{3, 4} };
    cout<<"closest Distance :"<<closest(points)<<endl;
    return 0;
}
