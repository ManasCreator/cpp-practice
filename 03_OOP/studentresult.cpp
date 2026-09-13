// Q1. Create a class Student with roll number and name.
// Create a class Marks with marks of 3 subjects.
// Create a class Sports with sports marks.
// Derive a class Result from Student, Marks and Sports.
// Calculate total, percentage and display grade.
#include <iostream>
using namespace std;

class Student{
protected:
int roll;
string name;
public:
void getinfo(){
    cout<<"Enter Name"<<endl;
    cin>>name;
    cout<<"Enter Roll No"<<endl;
    cin>>roll;
}
};

class Marks{
protected:
int m1,m2,m3;
public:
void getmarks(){
    cout<<"Enter Marks 1"<<endl;
    cin>>m1;
    cout<<"Enter Marks 2"<<endl;
    cin>>m2;
    cout<<"Enter Marks 3"<<endl;
    cin>>m3;
}
};

class Sport{
protected:
int sm;
public:
void sportmarks(){
cout<<"Enter Sports Marks"<<endl;
cin>>sm;
}

};

class Result: public Student,public Marks,public Sport{
protected:
int total;
float per;
public:
void calculate(){
    total=m1+m2+m3+sm;
    per=total/4;

}
void display(){
    cout<<"Name : "<<name<<endl;
    cout<<"Roll No : "<<roll<<endl;
    cout<<"Total Marks : "<<total<<endl;
    cout<<"Percentage : "<<per<<endl;
}
};

int main() {
    Result r;
    r.getinfo();
    r.getmarks();
    r.sportmarks();
    r.calculate();
    r.display();
    return 0;
}