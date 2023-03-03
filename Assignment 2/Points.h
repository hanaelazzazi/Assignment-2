#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

// creating a class called Points
class Points
{
    public:
        
        // Member function
        Points();
        Points(float, float);
        void set_x(float);
        void set_y(float);
        float get_x() const;
        float get_y() const;
        void display_point() const;
        float distance(const Points &p);
        
    private:
        
        // Data members
        float x;
        float y;
};




