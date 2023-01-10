#pragma once
#include<iostream>
using namespace std;

class Truck
{   public:
        string driver;
        double petrol;
        string regNo;
        int fullMileage;
        int emptyMileage;
        Truck(){

        }
        Truck(string x, string y , string z, string h, string m){
             driver=x;
             petrol=stod(y); //stod is string to double converted, taking line as string from file and then converting to respective types
             regNo=z;
             fullMileage=stoi(h); //stoi is string to integer converter
             emptyMileage=stoi(m);

        }
};

