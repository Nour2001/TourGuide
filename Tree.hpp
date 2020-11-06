#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include "Node.hpp"
#include <string>
#include <iomanip>

class Tree{
public:
    
    Tree();
    ~Tree();
    
    void insert(double x1, double y1,string name_of_cit,long population,double cost_of_living,double net_salary,Node* curr_node);
    Node* search(double x1, double y1, Node* curr_node);
    Node* help_search(double x1, double y1, Node* curr_node);
    void print(Node* curr_node);
    void q_max(double x1, double y1, string d, char attr, Node* curr_node);
    void q_min(double x1, double y1, string d, char attr,Node* curr_node);
    void q_total(double x1, double y1, string d, char attr,Node* curr_node);
    void trav_max(Node* t_node, char attr);
    void trav_min(Node* t_node, char attr);
    void trav_total(Node* t_node, char attr);
    void clear();
    Node* get_root();
    int get_size();
    void set_size(int size_);
    static double max;
    static double min;
    static string city_name;
    
private:
    int size;
    Node* root;
};

#endif 
