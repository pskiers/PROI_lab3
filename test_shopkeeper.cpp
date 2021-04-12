#include <iostream>
#include "shopkeeper.h"
#include <string>


int main()
{
    shopkeeper adam, krzys;
    adam.set_name("adam");
    adam.set_surname("pan");
    adam.set_salary(1234);
    adam.change_permission(2, false);
    adam.change_experience(123, true);
    adam.add_department("toys1");
    adam.add_department("toys2");
    adam.rm_department("toys1");
    std::cout<<adam.get_name()<<"\n"<<adam.get_surname()<<"\n"<<adam.get_experionce()<<"\n"<<adam.get_permission()<<"\n"<<adam.get_salary()<<"\n";
    bool cond1 = (adam == krzys);
    bool cond2 = (adam != krzys);
    std::cout<<cond1<<" = false\n"<<cond2<<" = true\n";
    krzys = adam;
    cond1 = (adam == krzys);
    cond2 = (adam != krzys);
    std::cout<<cond1<<" = true\n"<<cond2<<" = false\n";
    return 0;
}

