#include "test_thing.h"
#include "shopkeeper.h"
#include <string>
#include <iostream>
#include <limits>
#include <vector>

void clear_cin()
{
    std::cin.clear();
    std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
}

void do_smth(shopkeeper *the_obj, std::string msg)
{
    if(msg == "set_his_name")
    {
        std::string new_name;
        std::cout<<"Enter new name: ";
        std::cin>>new_name;
        int fail = the_obj->set_name(new_name);
        if(fail != 0)std::cout<<"You entered bad name\n";
        else std::cout<<"Changed the name\n";
    }
    else if(msg == "set_his_surname")
    {
        std::string new_surname;
        std::cout<<"Enter new surname: ";
        std::cin>>new_surname;
        int fail = the_obj->set_surname(new_surname);
        if(fail != 0)std::cout<<"You entered bad surname\n";
        else std::cout<<"Changed the surname\n";
    }
    else if(msg == "set_his_salary")
    {
        int new_salary;
        std::cout<<"Enter new salary: ";
        std::cin>>new_salary;
        if(std::cin.fail())
        {
            clear_cin();
            std::cout<<"Bad salary\n";
        }
        else
        {
            the_obj->set_salary(new_salary);
            std::cout<<"Changed salary";
        }
    }
    else if(msg == "change_his_permission_level")
    {
        std::string mode;
        int new_level;
        std::cout<<"Do you want to use absolute mode?\n";
        std::cin>>mode;
        std::cout<<"Enter new permission level: ";
        std::cin>>new_level;
        if(std::cin.fail())
        {
            clear_cin();
            std::cout<<"Bad new level";
        }
        if(mode == "yes")
        {
            int fail=the_obj->change_permission(new_level, true);
            if (fail == 0) std::cout<<"Changed permission level\n";
            else std::cout<<"Bad new level\n";
        }
        else if(mode == "no")
        {
            int fail=the_obj->change_permission(new_level, false);
            if (fail == 0) std::cout<<"Changed permission level\n";
            else std::cout<<"Bad new level\n";
        }
        else std::cout<<"Didn't understand\n";
    }
    else if(msg == "change_his_experience")
    {
        std::string mode;
        int new_experience;
        std::cout<<"Do you want to use absolute mode?\n";
        std::cin>>mode;
        std::cout<<"Enter new experience: ";
        std::cin>>new_experience;
        if(std::cin.fail())
        {
            clear_cin();
            std::cout<<"Bad new experience";
        }
        if(mode == "yes")
        {
            int fail=the_obj->change_experience(new_experience, true);
            if (fail != 0) std::cout<<"Changed experience\n";
            else std::cout<<"Bad new experience\n";
        }
        else if(mode == "no")
        {
            int fail=the_obj->change_experience(new_experience, false);
            if (fail != 0) std::cout<<"Changed experience\n";
            else std::cout<<"Bad new experience\n";
        }
        else std::cout<<"Didn't understand\n";
    }
    else if(msg == "add_departmen_to_him")
    {
        std::cout<<"Enter new department: ";
        std::string dep;
        std::cin>>dep;
        the_obj->add_department(dep);
        std::cout<<"Added the new department\n";
    }
    else if(msg == "remove_one_of_his_departments")
    {
        std::cout<<"Enter the department to be removed: ";
        std::string dep;
        std::cin>>dep;
        the_obj->rm_department(dep);
        std::cout<<"We did it boys "<<dep<<" is no more\n";
    }
    else if(msg == "remove_all_of_his_departments")
    {
        std::cout<<"As you whish\n";
        the_obj->rm_all_departments();
    }
    else if(msg == "print_him_out")
    {
        std::cout<<*the_obj<<"\n";
    }
    else if(msg == "get_his_name")
    {
        std::cout<<the_obj->get_name()<<"\n";
    }
    else if(msg == "get_his_surname")
    {
        std::cout<<the_obj->get_surname()<<"\n";
    }
    else if(msg == "get_his_salary")
    {
        std::cout<<the_obj->get_salary()<<" PLN\n";
    }
    else if(msg == "get_his_permission_level")
    {
        std::cout<<the_obj->get_permission()<<"\n";
    }
    else if(msg == "get_his_experience")
    {
        std::cout<<the_obj->get_experionce()<<" days\n";
    }
    else if(msg == "get_his_departments")
    {
        std::vector <std::string> departments;
        departments = the_obj->get_departments();
        for(auto i = departments.begin(); i!=departments.end(); ++i)
        {
            std::cout<<*i<<" ";;
        }
        std::cout<<"\n";
    }
    else
    {
        std::cout<<"Bad message entered\n";
    }
}

