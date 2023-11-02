#include <iostream>

using namespace std;

double divisor(double numerator, double denominator){
    //this function divides two numbers and returns the result
    return numerator/denominator;
}

double multiplier(double left, double right){
    //this function multiply two numbers and returns the result
    return left * right;
}

int main(){
    
    const int months = 12;
    const int percentDenominator = 100;
    
    double principal = 0.0;
    
    cout << "Enter the principal amount: ";
    
    cin >> principal;
    
    double interest = 0;
    
    cout << "Enter the interest rate(%): ";
    
    cin >> interest;
    
    double after_interest = divisor(interest, percentDenominator);
    
    int year = 30;
    
    cout << "Enter the year of loan: ";
    
    cin >> year;
    
    double monthInterst = divisor(interest,months);
    
    double totalMonth = multiplier(months, year);
    
    cout << principal << " " << interest << " " << year << " "
    << monthInterst << " " << totalMonth << endl;
    
    return 0;
}
