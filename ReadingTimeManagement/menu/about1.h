#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>
using namespace std;

//create class
class About{
    public:
        //classify relevant info
        void about(){
            system("cls");
            cout<<"***Please choose following info***"<<"\n\n"<<endl;
            cout<<"    Basic info(Option b)"<<endl;
            cout<<"    Student info(Option m)"<<endl;
            cout<<"\n"<<"Back to Front(Option N) Previous page(Option P) Exit(Option E) Menu(Option M)";
            cout<<"\n"<<"Choose:";
        }
        //student info
        void member(){
            system("cls");
            cout<<"Member info："<<"\n"<<endl;
            cout<<"Leader：Alex"<<endl;
            cout<<"    ID：ah3922"<<endl;
            cout<<"    Major：Computer Science"<<endl;
            cout<<"    Class：2022"<<"\n"<<endl;
            cout<<"Member：Joe"<<endl;
            cout<<"    ID：js3022"<<endl;
            cout<<"    Major：Computer Science"<<endl;
            cout<<"    Class：2022"<<"\n"<<endl;
            cout<<"Member：Kim"<<endl;
            cout<<"    ID：kk1532"<<endl;
            cout<<"    Major：Computer Science"<<endl;
            cout<<"    Class：2022"<<"\n"<<endl;
            cout<<"\n"<<"Back to Front(Option N) Previous page(Option P) Exit(Option E) Menu(Option M)";
            cout<<"\n"<<"Choose:";
        }
        //basic information
        void basic(){
            system("cls");
            cout<<"Basic Info："<<"\n"<<endl;
            cout<<"Name:"<<endl;
            cout<<"    Reading Time Management System"<<"\n"<<endl;
            cout<<"Version:"<<endl;
            cout<<"    Version：v1.0"<<"\n"<<endl;
        }
};
