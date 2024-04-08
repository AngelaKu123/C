#include "Line.h"
#include "Line2.h"
#include "Circle.h"
#include "Circle2.h"
// #include "List.h"
// #include "LnList.h"

#include <iostream>

using namespace std;

int main(){
    cout << "*******************LINE1*************************" << endl;
    Line l1(2,3,5,6),l2;
    cout << "L1 point(" << l1.get_x0() << "," << l1.get_y0() << "), (" << l1.get_x1() << "," << l1.get_y1() << ")" << endl;
    cout << "L1 slope = " << l1.slope() << ", y_intercept = " << l1.y_intercept() << endl;
    l1.vshift(1);
    cout << "Do shift(1)~" << endl;
    cout << "new L1 point(" << l1.get_x0() << "," << l1.get_y0() << "), (" << l1.get_x1() << "," << l1.get_y1() << ")" << endl;
    cout << "Input 4 number (two point) to create Line1 > ";
    cin >> l2;
    cout << "You create a Line1! -> " << l2 << endl;

    cout << "*******************LINE2************************" << endl;
    Line2 l3(1,2,3,4),l4(7,7,7,7);
    cout << "Input 3 number (ax+by+c) to create Line2 > ";
    cin >> l3;
    cout << "You create a Line2! -> " << l3 << endl;
    l3.normal(l4);
    cout << "The normal vector equation of the line -> " << l4 << endl;

    cout << "*******************CIRCLE1**********************" << endl;
    Circle c1(0,0,5),c2(33,33);
    cout << "C1 radius = " << c1.radius_of() << endl;
    c1.is_inside(1,1) 
        ? cout << "Point(1,1) in C1" << endl
        : cout << "Point(1,1) Not in C1" << endl;
    cout << "Change center~" << endl;
    c1.set_center(100,100);
    c1.is_inside(1,1) 
        ? cout << "Point(1,1) in C1" << endl
        : cout << "Point(1,1) Not in C1" << endl;
    cout << c2 << endl;

    cout << "*******************CIRCLE2**********************" << endl;
    Circle2 c3(0,0,6,6);
    c3.is_inside(1,1) 
        ? cout << "Point(1,1) in C3" << endl
        : cout << "Point(1,1) Not in C3" << endl;

    /*cout << "*******************LIST*************************" << endl;
    List ls;
    List *pls = new List();
    ls.insert_at(0,7);
    ls.insert_at(0,5);
    ls.insert_at(0,1);
    ls.insert_at(3,3);
    cout << "This list --> [" << ls.value_at(0) << " " << ls.value_at(1) << " " << ls.value_at(2) << " " << ls.value_at(3) << "]" << endl;
    ls.remove_at(1);
    ls.remove_at(2);
    cout << ls << endl;
    delete pls;

    cout << "*******************LNLIST***********************" << endl;
    LnList lnls;
    LnList *plnls = new LnList();
    lnls.insert(8);
    lnls.insert(7);
    lnls.insert(6);
    lnls.insert(4);
    lnls.insert(2);
    lnls.find(7) 
        ? cout << "7 in Lnlist" << endl
        : cout << "7 Not in LnList" << endl;
    lnls.remove(7);
    lnls.find(7) 
        ? cout << "7 in Lnlist" << endl
        : cout << "7 Not in LnList" << endl;
    delete plnls;
    cout << "*******************END**************************" << endl;*/
    return 0;
}
