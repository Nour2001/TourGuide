#include <iostream>
#include "Node.hpp"
#include "Tree.hpp"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

 double Tree::max=0;
double Tree::min=99999;
string Tree::city_name="";

int main() {
    Tree* q_tree = new Tree();
   string cmdline; //entire line
   string command;
     getline(cin, cmdline); //sets cmdline to be the whole line
   
   double x = 0;
   double y=0;
   string name_of_city="";
   long population=0;
   double cost_of_living=0;
   double net_salary=0;
    string d="";
    char semicolon = '\0';
    char attr = '\0';
    char first_d='\0';
    char sec_d='\0';
    
    while (!cin.eof()) {
        istringstream iss(cmdline);
             iss >> command; //sets comand to be the first string it finds
          string str = iss.str();
       if (command == "exit") {
           delete q_tree;
           break;
       }
       else if (command == "size") {
           std::cout <<"tree size ";
        std::cout << q_tree->get_size()<< std::endl;
       }else if(command == "i"){
           name_of_city=str.substr(2, str.find(';')-2);
           iss = istringstream(str.substr(str.find(';')+1));
           iss>>x>>semicolon>>y>>semicolon>>population>>semicolon>>cost_of_living>>semicolon>>net_salary;
           q_tree->insert(x, y, name_of_city, population, cost_of_living, net_salary,q_tree->get_root());
       }else if (command == "s" ){
           iss>>x>>semicolon>>y;
           q_tree->search(x, y, q_tree->get_root());
       }else if (command == "print" ){
           q_tree->print(q_tree->get_root());
           if(Tree::city_name.size()>0){
               Tree::city_name.pop_back();
               std::cout<<Tree::city_name<<std::endl;
           }
           Tree::city_name="";
       }else if (command == "q_max" ){
           iss>>x>>semicolon>>y>>semicolon>>first_d>>sec_d>>semicolon>>attr;
           d = "";
           d+=first_d;
           d+=sec_d;
           q_tree->q_max(x, y, d, attr,q_tree->get_root());
       }else if (command == "q_min" ){
           iss>>x>>semicolon>>y>>semicolon>>first_d>>sec_d>>semicolon>>attr; 
           d = "";
           d+=first_d;
           d+=sec_d;
           q_tree->q_min(x, y, d, attr, q_tree->get_root());
       }else if (command == "q_total" ){
           iss>>x>>semicolon>>y>>semicolon>>first_d>>sec_d>>semicolon>>attr;
           d = "";
           d+=first_d;
           d+=sec_d;
           q_tree->q_total(x, y, d, attr, q_tree->get_root());
       }else if (command == "clear" ){
           delete q_tree;
           q_tree= new Tree();
           std::cout<<"success"<<std::endl;
       }
    getline(cin, cmdline);
   }
    return 0;
}
     

