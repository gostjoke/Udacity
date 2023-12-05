#include <cassert>
#include <stdexcept>
#include <string>
// TODO: Define "Student" class
class Student {
 public:
  // constructor
    Student(std::string name, int grade, float gpa): name_(name), grade_(grade), gpa_(gpa){
        Validate();
    }
  // accessors
    std::string Name() const {return name_;}
    int Grade() const {return grade_;}
    float GPA() const {return gpa_;}
  // mutators
    void Name(std::string name){
        name_ = name;
        Validate();
    }
    void Grade(int grade){
        grade_ = grade;
        Validate();
    }
    void GPA(float gpa){
        gpa_ = gpa;
        Validate();
    }
    
    
    
 private:
     std::string name_;
     int grade_;
     float gpa_;
     void Validate() {
         if(Grade() < 0 || Grade() > 12 || GPA() < 0.0 || GPA() > 4.0)
             throw std::invalid_argument("argument out of bounds");
     }
};

// TODO: Test
int main() {
    Student david("David Sliver", 10, 4);
    assert(david.Name() == "David Sliver");
    assert(david.Grade() == 10);
    assert(david.GPA() == 4);
    
    bool caught{false};
    try {
        david.Grade(20);
    }
    catch(...) {
        caught = true;
    }
    assert(caught);
    
}