#include <iostream>
#include "Tree.hpp"
#include "Node.hpp"
#include <string>
#include <iomanip>
using namespace std; 

Tree::Tree(){
    root = nullptr;
    size=0;
}

Tree::~Tree(){
    delete root;
}
Node* Tree::get_root(){
    return root; 
}
int Tree::get_size(){
    return size;
}
void Tree::set_size(int size_){
    size=size_;
}

void Tree::insert(double x1,double y1,string name_of_cit,long population,double cost_of_living,double net_salary, Node* curr_node){
    Node* in_node=new Node(x1,y1,name_of_cit,population,cost_of_living,net_salary);
    if(root ==NULL){
        root = in_node;
        size=size+1;
        cout<<"success"<<endl;
        return;
    }
    if(curr_node->get_x() == x1 && curr_node->get_y() == y1 ){
        cout<<"failure"<<endl;
        return;
    }else if(x1>=curr_node->get_x() && y1> curr_node->get_y()){
        if(curr_node->get_NE()== NULL){
            curr_node->set_NE(in_node);
            size=size+1;
            cout<<"success"<<endl;
            return;
        }else{
            curr_node = curr_node->get_NE();
            insert(x1,y1,name_of_cit,population,cost_of_living,net_salary,curr_node);
        }
    }else if(x1<curr_node->get_x() && y1>= curr_node->get_y()){
        if(curr_node->get_NW()==NULL){
            curr_node->set_NW(in_node);
            size=size+1;
            cout<<"success"<<endl;
            return;
        }else{
            curr_node = curr_node->get_NW();
            insert(x1,y1,name_of_cit,population,cost_of_living,net_salary,curr_node);
        }
    }else if(x1<=curr_node->get_x() && y1< curr_node->get_y()){
        if(curr_node->get_SW()==NULL){
            curr_node->set_SW(in_node);
            size=size+1;
            cout<<"success"<<endl;
            return;
        }else{
            curr_node = curr_node->get_SW();
            insert(x1,y1,name_of_cit,population,cost_of_living,net_salary, curr_node);
        }
    }else if(x1>curr_node->get_x() && y1<= curr_node->get_y()){
        if(curr_node->get_SE()==NULL){
            curr_node->set_SE(in_node);
            size=size+1;
            cout<<"success"<<endl;
            return;
        }else{
            curr_node= curr_node->get_SE();
            insert(x1,y1,name_of_cit,population,cost_of_living,net_salary, curr_node);
        }
    }
    delete in_node;
}

Node* Tree::search(double x1, double y1, Node* curr_node){
    if(curr_node == NULL){
        cout<<"not found"<<endl;
        return nullptr;
    }
     if(curr_node->get_x()==x1 && curr_node->get_y()==y1){
        cout<<"found "<<curr_node->get_name_of_city()<<endl;
        return nullptr;
    }else if(x1>=curr_node->get_x() && y1> curr_node->get_y()){
        curr_node=search(x1,y1,curr_node->get_NE());
    }else if(x1<curr_node->get_x() && y1>= curr_node->get_y()){
        curr_node=search(x1,y1,curr_node->get_NW());
    }else if(x1<=curr_node->get_x() && y1< curr_node->get_y()){
        curr_node=search(x1,y1,curr_node->get_SW());
    }else if(x1>curr_node->get_x() && y1<= curr_node->get_y()){
        curr_node=search(x1,y1,curr_node->get_SE());
    }
    return curr_node;
}

Node* Tree::help_search(double x1, double y1, Node* curr_node){
    
    if(curr_node == nullptr){
        cout<<"failure"<<endl;
        return nullptr;
    }
     if(curr_node->get_x()==x1 && curr_node->get_y()==y1){
         return curr_node;
    }else if(x1>=curr_node->get_x() && y1> curr_node->get_y()){
         curr_node=help_search(x1,y1,curr_node->get_NE());
    }else if(x1<curr_node->get_x() && y1>= curr_node->get_y()){
        curr_node=help_search(x1,y1,curr_node->get_NW());
    }else if(x1<=curr_node->get_x() && y1< curr_node->get_y()){
        curr_node=help_search(x1,y1,curr_node->get_SW());
    }else if(x1>curr_node->get_x() && y1<= curr_node->get_y()){
        curr_node=help_search(x1,y1,curr_node->get_SE());
    }
    return curr_node;
}

void Tree::trav_max(Node* t_node, char attr){ //TA Arnab Gosh helped me construct this function by giving me ideas of the best way to implement it
    if(t_node ==NULL){
        return;
    }
    if(attr=='p' && (t_node->get_population()>Tree::max)){
        Tree::max=t_node->get_population();
    }
    if(attr=='r' && (t_node->get_cost_of_living()>Tree::max)){
        Tree::max=t_node->get_cost_of_living();
    }
    if(attr=='s' && (t_node->get_net_salary()>Tree::max)){
        Tree::max=t_node->get_net_salary();
    }
    trav_max(t_node->get_NE(), attr);
    trav_max(t_node->get_NW(), attr);
    trav_max(t_node->get_SW(), attr);
    trav_max(t_node->get_SE(), attr);
    return;
}
void Tree::trav_min(Node* t_node, char attr){ //TA Arnab Gosh helped me construct this function by giving me ideas of the best way to implement it
    if(t_node ==NULL){
        return;
    }
    if(attr=='p' && (t_node->get_population()<Tree::min)){
        Tree::min=t_node->get_population();
    }
    if(attr=='r' && (t_node->get_cost_of_living()<Tree::min)){
        Tree::min=t_node->get_cost_of_living();
    }
    if(attr=='s' && (t_node->get_net_salary()<Tree::min)){
        Tree::min=t_node->get_net_salary();
    }
    trav_min(t_node->get_NE(), attr);
    trav_min(t_node->get_NW(), attr);
    trav_min(t_node->get_SW(), attr);
    trav_min(t_node->get_SE(), attr);
    return;
}
void Tree::trav_total(Node* t_node, char attr){ //TA Arnab Gosh helped me construct this function by giving me ideas of the best way to implement it
    if(t_node ==NULL){
        return;
    }
    if(attr=='p'){
        Tree::max += t_node->get_population();
    }
    if(attr=='r'){
        Tree::max += t_node->get_cost_of_living();
    }
    if(attr=='s'){
        Tree::max+=t_node->get_net_salary();
    }
    trav_total(t_node->get_NE(), attr);
    trav_total(t_node->get_NW(), attr);
    trav_total(t_node->get_SW(), attr);
    trav_total(t_node->get_SE(), attr);
    return;
}
void Tree::q_max(double x1, double y1, string d, char attr, Node* curr_node){ //TA Arnab Gosh helped me construct this function by giving me ideas of the best way to implement it
    Node* temp;
    temp = help_search(x1, y1, curr_node);
    if(temp == nullptr){
        cout<<"failure"<<endl;
        return;
    }
    if(d=="NE"){
        temp=temp->get_NE();
        if(temp==nullptr){
            cout<<"failure"<<endl;
            return;
        }else{
            trav_max(temp, attr);
        }
    }else if(d=="NW"){
        temp=temp->get_NW();
        if(temp==nullptr){
            cout<<"failure"<<endl;
            return;
        }else{
            trav_max(temp, attr);
        }
    }else if(d=="SW"){
        temp=temp->get_SW();
        if(temp==nullptr){
            cout<<"failure"<<endl;
            return;
        }else{
            trav_max(temp, attr);
        }
    }else if(d=="SE"){
        temp=temp->get_SE();
        if(temp==nullptr){
            cout<<"failure"<<endl;
            return;
        }else{
            trav_max(temp, attr);
        }
   }
    if( attr !='p'){
        cout<<fixed<<setprecision(2)<<"max "<<Tree::max<<endl;
    }else{
        cout<<"max "<< int(Tree::max)<<endl;
    }
    
    Tree::max=0;
}

void Tree::q_min(double x1, double y1, string d, char attr, Node* curr_node){ //TA Arnab Gosh helped me construct this function by giving me ideas of the best way to implement it
    Node* temp;
    temp = help_search(x1, y1, curr_node);
    if(temp == nullptr){
        cout<<"failure"<<endl;
        return;
    }
    if(d=="NE"){
        temp=temp->get_NE();
        if(temp==nullptr){
            cout<<"failure"<<endl;
            return;
        }else{
            if(attr=='p'){
                Tree::min=temp->get_population();
            }
            if(attr=='r'){
                Tree::min=temp->get_cost_of_living();
            }
            if(attr=='s'){
                Tree::min=temp->get_net_salary();
            }
            trav_min(temp, attr);
        }
    }else if(d=="NW"){
        temp=temp->get_NW();
        if(temp==nullptr){
            cout<<"failure"<<endl;
            return;
        }else{
            if(attr=='p'){
                Tree::min=temp->get_population();
            }
            if(attr=='r'){
                Tree::min=temp->get_cost_of_living();
            }
            if(attr=='s'){
                Tree::min=temp->get_net_salary();
            }
            trav_min(temp, attr);
        }
    }else if(d=="SW"){
        temp=temp->get_SW();
        if(temp==nullptr){
            cout<<"failure"<<endl;
            return;
        }else{
            if(attr=='p'){
                Tree::min=temp->get_population();
            }
            if(attr=='r'){
                Tree::min=temp->get_cost_of_living();
            }
            if(attr=='s'){
                Tree::min=temp->get_net_salary();
            }
            trav_min(temp, attr);
        }
    }else if(d=="SE"){
        temp=temp->get_SE();
        if(temp==nullptr){
            cout<<"failure"<<endl;
            return;
        }else{
            if(attr=='p'){
                Tree::min=temp->get_population();
            }
            if(attr=='r'){
                Tree::min=temp->get_cost_of_living();
            }
            if(attr=='s'){
                Tree::min=temp->get_net_salary();
            }
            trav_min(temp, attr);
        }
   }
    if( attr !='p'){
        cout<<fixed<<setprecision(2)<<"min "<<Tree::min<<endl;
    }else{
        cout<<"min "<< int(Tree::min)<<endl;
    }

    Tree::min=99999;
}
void Tree::q_total(double x1, double y1, string d, char attr, Node* curr_node){ //TA Arnab Gosh helped me construct this function by giving me ideas of the best way to implement it 
    Node* temp;
    temp = help_search(x1, y1, curr_node);
    if(temp == nullptr){
        cout<<"failure"<<endl;
        return;
    }
    if(d=="NE"){
        temp=temp->get_NE();
        if(temp==nullptr){
            cout<<"failure"<<endl;
            return;
        }else{
            trav_total(temp, attr);
        }
    }else if(d=="NW"){
        temp=temp->get_NW();
        if(temp==nullptr){
            cout<<"failure"<<endl;
            return;
        }else{
            trav_total(temp, attr);
        }
    }else if(d=="SW"){
        temp=temp->get_SW();
        if(temp==nullptr){
            cout<<"failure"<<endl;
            return;
        }else{
            trav_total(temp, attr);
        }
    }else if(d=="SE"){
        temp=temp->get_SE();
        if(temp==nullptr){
            cout<<"failure"<<endl;
            return;
        }else{
            trav_total(temp, attr);
        }
   }
    if( attr !='p'){
        cout<<fixed<<setprecision(2)<<"total "<<Tree::max<<endl;
    }else{
        cout<<"total "<< int(Tree::max)<<endl;
    }
    
    Tree::max=0;
    Tree::max=0;
}

void Tree::print(Node* curr_node){
    if(curr_node ==NULL){
        return;
    }
    print(curr_node->get_NE());
    print(curr_node->get_NW());
    Tree::city_name += curr_node->get_name_of_city()+" ";
    print(curr_node->get_SW());
    print(curr_node->get_SE());    
}

