#include <iostream>


using namespace std;

int main(){
    const int month = 12;
    
    double principal = 0.0;
    
    cout << "Enter the principal amount:";
    
    cin >>principal;
    
    double interest = 0.0;
    cout << "Enter the interest amount:";
    
    cin >>interest;
    
    int maturity = 30;
    
    double mInterst = interest/month;
    long mtotal = maturity * month;
    
    cout << principal << " "<< interest <<" "<< maturity <<
    " "<< mInterst << " " << mtotal << endl;
    
    return 0;
}
