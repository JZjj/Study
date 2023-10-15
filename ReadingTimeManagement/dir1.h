#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctime>
using namespace std;


//front page
void dirMessage(){
    system("cls");
    time_t t=time(0);
    char *ct=ctime(&t);
    cout<<"    The current time is"<<ct<<"\n"<<endl;
    cout<<"***Welcome to Extracurriculum Reading Time Management System***"<<"\n\n"<<endl;
    cout<<"    Start(Option s)"<<endl;
    cout<<"    Menu(Option m)"<<endl;
    cout<<"\n"<<"Exit(Option E)"<<endl;
    cout<<"\n"<<"Choose:";
}
