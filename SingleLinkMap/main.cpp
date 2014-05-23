#include "singlelinkmap.h"
#include <iostream>
using std::cout; using std::endl; using std::ostream;
#include <random>
using std::default_random_engine; using std::normal_distribution;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include<cmath>
using std::round;

int main (){
    vector<string> names{"Jane", "Fred", "Irving", "Sam", "Deb", "Molly"};
    default_random_engine reng;
    normal_distribution<>dist(3,1);
    long max_num=100;

    // node test
    Node<long,string> n(10, "Rich");
    n.print_node(cout) << endl;

    // append test
    SingleLinkMap<long, string> lst;
    for(long i=0;i<names.size();i++){
	lst.append_back(i, names[i]);
    }

    // copy test
    // lists should be different (appended only to new_lst)
    SingleLinkMap<long,string> new_lst(lst);
    new_lst.append_back(-1, "Bill");
    new_lst.print_list(cout) << endl;
    lst.print_list(cout) << endl;

    // assignment test
    // lists should be different (appened only to lst)
    lst = new_lst;
    lst.append_back(-5, "Bob");
    new_lst.print_list(cout) << endl;
    lst.print_list(cout) << endl;

    // find_then_front test
    // moved -1:Bill to front
    cout << "Looking for -1:"<<lst.find_then_front(-1)<<endl;
    cout << "Looking for -1:"<<lst.find_then_front(-1)<<endl;
    lst.print_list(cout) << endl;    
    // failed find test
    cout << "Failed Find -123:"<<lst.find_then_front(-123)<<endl;

    // find_then_swap test
    // -5:Bob should move up two
    cout << "Looking for -5:"<<lst.find_then_swap(-5)<<endl;
    cout << "Looking for -5:"<<lst.find_then_swap(-5)<<endl;
    lst.print_list(cout) << endl;    
    // failed find test
    cout << "Failed Find -123:"<<lst.find_then_swap(-123)<<endl;

    // normal dist run using find then front. 
    // what does the order look like?
    for(int i=0, j=round(dist(reng)); 
	i<max_num; 
	i++, j=round(dist(reng)))
    {
	cout << j << ", ";
	lst.find_then_front(j);
    }
    cout << endl;
    lst.print_list(cout)<<endl;

    // normal dist run using find then swap. 
    // what does the order look like?
    for(int i=0, j=round(dist(reng)); 
	i<max_num; 
	i++, j=round(dist(reng)))
    {
	cout << j << ", ";
	lst.find_then_swap(j);
    }
    cout << endl;
    lst.print_list(cout)<<endl;
}
    
