#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <string>
#include <iomanip>
using namespace std;
class Node{

public:
    Node();
    Node(double x_,double y_,string name_of_city_,long population_,double cost_of_living_,double net_salary_);
    ~Node();
    
    double  get_x();
    double  get_y();
    string  get_name_of_city ();
    long    get_population ();
    double  get_cost_of_living();
    double  get_net_salary ();
    Node*   get_NE();
    Node*   get_NW();
    Node*   get_SW();
    Node*   get_SE();
    
    void    set_name_of_city (string name_of_city_);
    void    set_population (long population_);
    void    set_cost_of_living (double cost_of_living_);
    void    set_net_salary (double net_salary_);
    void    set_x(double x_);
    void    set_y(double y_);
    void    set_NE(Node* NE_);
    void    set_NW(Node* NW_);
    void    set_SW(Node* SW_);
    void    set_SE(Node* SE_);
   
private:
    double x;
    double y;
    string name_of_city;
    long population;
    double cost_of_living;
    double net_salary;
    Node *NE;
    Node *NW;
    Node *SE;
    Node *SW;
};

#endif
