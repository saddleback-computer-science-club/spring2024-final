#include<iostream>
#include "Major.hpp"
using namespace std;

class University{
    private:
     // Unique identifier for the university
      int uni_id;

      // Name of the university
     string uni_name; 

     // List of majors offered at the university
    vector<Major> major_list; 

    public:
     // Constructor to initialize a University object
     University(int id, string name) : uni_id(id), uni_name(name) {}

        /*University Class:

        Constructor: To initialize the University object with default or given values.
        addMajor(Major major): To add a Major object to the major_list.
        getMajor(string majorName): To retrieve a Major object by its name.
       getUniName(): To get the name of the university.
        getUniId(): To get the ID of the university.   
        
        */


    
};