#include "Node.hpp"
#include <string>
#include <iostream>

using namespace std;

Node::Node(){
    x=0;
    y=0;
    name_of_city = "";
    population = 0;
    net_salary = 0;
    cost_of_living =0;
    NE= nullptr;
    NW=nullptr;
    SE=nullptr;
    SW=nullptr;
}
Node::Node(double x_, double y_, string name_of_city_, long population_, double cost_of_living_, double net_salary_){
    x=x_;
    y=y_;
    name_of_city = name_of_city_;
    population = population_;
    net_salary = net_salary_;
    cost_of_living =cost_of_living_;
    NE=NULL;
    NW=NULL;
    SE=NULL;
    SW=NULL;
}
Node::~Node(){
    delete NE;
    delete SE;
    delete NW;
    delete SW;
}
string  Node:: get_name_of_city (){
    return name_of_city;
}
long   Node::get_population (){
    return population;
}
double  Node::get_cost_of_living(){
    return cost_of_living;
}
double  Node::get_net_salary (){
    return net_salary;
}
void    Node::set_name_of_city (string name_of_city_){
    name_of_city = name_of_city_;
}
void    Node::set_population (long population_){
    population= population_;
}
void    Node::set_cost_of_living (double cost_of_living_){
    cost_of_living=cost_of_living_;
}
void    Node::set_net_salary (double net_salary_){
    net_salary=net_salary_;
}

void Node::set_x(double x_){
    x=x_;
}
double Node:: get_x(){
    return x;
}
void Node::set_y(double y_){
    y=y_;
}
double Node::get_y(){
    return y;
}
Node* Node::get_NE(){
    return NE;
}
void Node::set_NE(Node* NE_){
    NE=NE_;
}
Node* Node::get_NW(){
    return NW;
}
void Node::set_NW(Node* NW_){
    NW=NW_;
}

Node* Node::get_SE(){
    return SE;
}
void Node::set_SE(Node* SE_){
    SE= SE_;
}

Node* Node::get_SW(){
    return SW;
}
void Node::set_SW(Node* SW_){
    SW=SW_;
}

