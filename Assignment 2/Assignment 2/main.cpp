//created by Hana Elazzazi 900222935
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "Points.h"
using namespace std;

//used .h file of class points
//default contructor
    Points::Points()
    {
        x=0.0;
        y=0.0;
    }
//parametrized constructor
    Points::Points(float x1, float y1)
    {
        x = x1;
        y = y1;
    }
//setter for x
    void Points::set_x (float x1)
    {
        x = x1;
    }
//getter for x
    float Points::get_x() const
    {
        return x;
    }
//setter for y
    void Points::set_y (float y1)
    {
        y = y1;
    }
//getter for y
    float Points::get_y() const
    {
        return y;
    }
//function to print out values of x and y
    void Points::display_point() const
    {
        //to output value giving two decimal places
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        
        cout<<"The value of x is: "<<x<<endl;
        cout<<"The value of y is: "<<y<<endl;
    }
    // function to calculate distance recieving p as a pass by reference to be changed in main
    float Points::distance(const Points &p)
    {
        return sqrt(pow(x-p.x,2)+pow(y-p.y,2));
    }
// funtion to find the center of cluster
Points Center(Points arr[], int n)
{
    //to store x and y for center
    float x1, y1;
    
    //for loop for each point in cluster while adding sum values
    for(int i=0; i<n; i++)
    {
        x1 = x1 + arr[i].get_x();
        y1 = y1 + arr[i].get_y();
    }
    
    //get average
    x1 = x1/n;
    y1 = y1/n;
    
    //creating a point center
    Points center;
    
    //setting values for x and y
    center.set_x(x1);
    center.set_y(y1);
    
    return center;
}

    //function used to find the closest cluster
void Closest(Points A[], Points B [], Points p, int n)
{
    //find the center of cluster A and B
    Points center_A = Center(A, n);
    Points center_B = Center(B, n);
    
    //if the distance between point p and center of A than the distance between point p and center of cluster B enter the loop
    if (p.distance(center_A) < p.distance(center_B))
    {
        cout << "The closest point to cluster A is: "<<endl;
    }
    else
    {
        cout << "The closest point to cluster B is: "<<endl;
    }
        
   //printing values
    p.display_point();
}
 
int main()
{
   //using srand to ensure that each time your run the program you get different results
    srand(time(0));
    int n = 200, m = 20;
    
    //create a clusterS
    Points *A = new Points[n];
    Points *B = new Points[n];
    Points *p = new Points[m];
    
    //creating values between 90 and 70
    for(int i = 0; i < n; i++)
    {
        float x = 70+(rand())*(90-70)/ RAND_MAX;
        float y = 70+(rand())*(90-70)/ RAND_MAX;
        
        A[i].set_x(x);
        A[i].set_y(y);
    }
    
    //creating values between 20 & 40
    for(int i = 0; i < n; i++)
    {
        float x = 20+(rand())*(40-20) / RAND_MAX;
        float y = 20+(rand())*(40-20)/ RAND_MAX;
        
        B[i].set_x(x);
        B[i].set_y(y);
    }

    //in the following for loops i used the static_cast<float> to allow the compiler to generate a division with an answer of type float .
    for(int i = 0; i < m; i++)
    {
        float x = 5+static_cast<float>(rand())*static_cast<float>(100-5)/ RAND_MAX;
        float y = 5+static_cast<float>(rand())*static_cast <float>(100-5)/ RAND_MAX;
        
        p[i].set_x(x);
        p[i].set_y(y);
    }
    
   //check which is closest to p
    for(int i = 0; i < m; i++)
    {
        Closest(A, B, p[i], n);
    }
    return 0;
}
