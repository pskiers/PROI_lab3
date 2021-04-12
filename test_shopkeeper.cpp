#include <iostream>
#include "shopkeeper.h"
#include <string>


int main()
{
    shopkeeper adam;
    adam.set_name("adam");
    adam.set_surname("pan");
    adam.set_salary(1234);
    adam.change_permission(2, false);
    adam.change_experience(123, true);
    adam.add_department("toys1");
    adam.add_department("toys2");
    adam.rm_department("toys1");
    std::cout<<adam.get_name()<<"\n"<<adam.get_surname()<<"\n"<<adam.get_experionce()<<"\n"<<adam.get_permission()<<"\n"<<adam.get_salary()<<"\n";
    std::cout<<adam;
    return 0;
}

