#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include "data1.h"
using namespace std;


class Rdis{
    public:
        //for search by name
        void reminderName() {
            system("cls");
            cout << "***Only for Name Search***\n\n" << endl;
            cout << "Please enter name:";
        }
        //for search by ID
        void reminderNumber(){
            system("cls");
            cout<<"***Only for ID Search***\n\n"<<endl;
            cout<<"Please enter ID:";
        }
        //for search by reading time
        void reminderTime(){
            system("cls");
            cout<<"***Only for search by reading time***\n\n"<<endl;
            cout<<"Please enter time:"<<endl;
        }
        //single search no result
        void studentNOTFOUND(){
            system("cls");
            cout<<"Do not find the student（return after 3s)";
            Sleep(3000);
        }
        //area no result
        void areaNOTFOUND(){
            system("cls");
            cout<<"Area no student（return after 3s)";
            Sleep(3000);
        }
        //finish search
        void FINISH(){
            cout<<"\n"<<"Finish search-Return front page(Option N) Previous page(Option P) Exit(Option E) Redo(Option R)"<<endl;
            cout<<"\n"<<"Please choose:";
        }
        //error
        void eFINISH(){
            cout<<"Return front page(Option N) Previous page(Option P) Exit(Option E) Redo(Option R)"<<endl;
            cout<<"\n"<<"Please choose:";
        }
};

class getData:public data{
    Rdis R;
    public:
        void name(){
            R.reminderName();
            string nam;
            cin>>nam;
            int def=100;
            for(int i=0;i<30;i++){
                if(nam==stu[i].name){
                    def=i;
                    break;
                }
            }
            if(def==100){
                R.studentNOTFOUND();
                name();
            }
            else{
                system("cls");
                cout<<"You are looking for:"<<endl;
                cout<<"\n"<<"Name is:"<<stu[def].name<<endl;
                cout<<"    ID is:"<<stu[def].ID<<endl;
                cout<<"    Major is:"<<stu[def].major<<endl;
                cout<<"    Class is:"<<stu[def].cls<<endl;
                cout<<"    Reading time is:"<<stu[def].time<<" h"<<endl;
                R.FINISH();
            }
        }
        //search by ID
        void number(){
            R.reminderNumber();
            string ID;
            cin>>ID;
            int def=100;
            for(int j=0;j<30;j++){
                if(ID==stu[j].ID){
                    def=j;
                    break;
                }
            }
            if(def==100){
                R.studentNOTFOUND();
                number();
            }
            else{
                system("cls");
                cout<<"You are searching:"<<endl;
                cout<<"\n"<<"Name is:"<<stu[def].name<<endl;
                cout<<"    ID is:"<<stu[def].ID<<endl;
                cout<<"    Major is:"<<stu[def].major<<endl;
                cout<<"    Class is:"<<stu[def].cls<<endl;
                cout<<"    Time is:"<<stu[def].time<<" h"<<endl;
                R.FINISH();
            }
        }
        //search by time
        void time(){
            R.reminderTime();
            float t1,t2;
            cout<<"Please enter start:";
            cin>>t1;
            cout<<"\n"<<"Enter end:";
            cin>>t2;
            int inc[30],in=0;
            if(t1>t2){
                float temp=t2;
                t2=t1;
                t1=temp;
            }
            for(int i=0;i<30;i++){
                if(stu[i].time>=t1&&stu[i].time<=t2){
                    inc[in]=i;
                    in++;
                }
            }
            for(int i=0;i<in;i++){
                for(int j=0;j<i;j++){
                    if(stu[inc[j]].time>stu[inc[i]].time){
                        int temp=inc[j];
                        inc[j]=inc[i];
                        inc[i]=temp;
                    }
                }
            }
            if(in==0){
                R.areaNOTFOUND();
                time();
            }
            else{
                system("cls");
                cout<<"You are looking for:"<<endl;
                for(int i=0;i<in;i++){
                    cout<<"\n"<<"Name is:"<<stu[inc[i]].name<<endl;
                    cout<<"    ID is:"<<stu[inc[i]].ID<<endl;
                    cout<<"    Major is:"<<stu[inc[i]].major<<endl;
                    cout<<"    Class is:"<<stu[inc[i]].cls<<endl;
                    cout<<"    Time is:"<<stu[inc[i]].time<<" h"<<endl;
                }
                R.FINISH();
            }
        }
};
