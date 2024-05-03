#include <iostream>
#include <map>
#include <string>
using namespace std;

class Major{

    private:
         // ID of the university offering this major
         int uni_id; 

         // Name of the major
        string major_name; 

         // GPA requirement for the major
        float gpa_req;


        // Map of required courses for the major
        map <string,vector<string>> required_courses; 
    public:

     // Constructor to initialize a Major object
    Major(int id, string name, float gpa) : uni_id(id), major_name(name), gpa_req(gpa) {}


/*        Major Class:

        Constructor: To initialize the Major object with default or given values.
        addRequiredCourse(string courseCategory, vector<string> courses): To add required courses to the required_courses map.
        getGPAReq(): To get the GPA requirement for the major.
        getRequiredCourses(): To get the map of required courses.
        …other getters and setters as needed.



*/

};