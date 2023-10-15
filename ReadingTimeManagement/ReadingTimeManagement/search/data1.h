#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctime>
using namespace std;

class data{
    public:
        struct Student
        {
            string name;
            string ID;
            string major;
            string cls;
            float time;
        }stu[30];
        
        //define read to get data，save to Student
        void read(){
            ifstream f;
            f.open("search/namefile.txt");
            for(int i=0;i<30;i++){
                f>>stu[i].name;
                f>>stu[i].ID;
                f>>stu[i].major;
                f>>stu[i].cls;
                f>>stu[i].time;
            }
        }
};
