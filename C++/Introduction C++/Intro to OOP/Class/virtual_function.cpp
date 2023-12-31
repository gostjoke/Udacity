// Example solution for Shape inheritance
#include <assert.h>
#include <cmath>

// TODO: Define pi
#define PI 3.14159
// TODO: Define the abstract class Shape
class Shape {
    // TODO: Define public virtual functions Area() and Perimeter()
    // TODO: Append the declarations with = 0 to specify pure virtual functions
    public:
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
};

// TODO: Define Rectangle to inherit publicly from Shape
class Rectangle: public Shape{
  // TODO: Declare public constructor
  public:
    Rectangle(double w, double h){ width_ = w; height_ = h;}
  // TODO: Override virtual base class functions Area() and Perimeter()
    double Area() const override {return width_ * height_;}
    double Perimeter() const override {return 2*(width_ + height_);}
  // TODO: Declare private attributes width and height
  private:
    double width_;
    double height_;
};
// TODO: Define Circle to inherit from Shape
class Circle: public Shape{
  // TODO: Declare public constructor
  public:
    Circle(double r){
        Circle::radius_= r;
    }
  // TODO: Override virtual base class functions Area() and Perimeter()
    double Area() const override {return (radius_*radius_)*PI;}
    double Perimeter() const override {return 2*(radius_)*PI;}
  // TODO: Declare private member variable radius
  private:
    double radius_;
};
// Test in main()
int main() {
  double epsilon = 0.1; // useful for floating point equality

  // Test circle
  Circle circle(12.31);
  assert(abs(circle.Perimeter() - 77.35) < epsilon);
  assert(abs(circle.Area() - 476.06) < epsilon);

  // Test rectangle
  Rectangle rectangle(10, 6);
  assert(rectangle.Perimeter() == 32);
  assert(rectangle.Area() == 60);
}