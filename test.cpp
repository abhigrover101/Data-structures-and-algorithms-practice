#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<cstdio>
#include<iostream>
using namespace std;

class Animal {
    public:
    void const display(){
        cout<<"Animal"<<endl;
    }
    virtual ~Animal(){
        cout<< "destroying animal"<<endl;
    }
};

class Leopard: public Animal {
    public:
        void const display(){
            cout<<"Leopard"<<endl;
        }

        ~Leopard()
        {
            cout<<"leo destroyed"<<endl;
        }
};
int main()
{
    Leopard *l=new Leopard ;
    Animal *a;
    a=l;
    delete a;
    //a->display();
    //delete &l;
    //a=0;
    //a->display();
    //return 0;

    //l.display();
//delete a;
}
