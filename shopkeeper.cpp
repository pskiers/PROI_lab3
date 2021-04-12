#include "shopkeeper.h"
#include <string>
#include <vector>
#include <cctype>
#include <iostream>

int shopkeeper::set_name(std::string new_name)
{
    if (!new_name.empty())
    {
        if (isalpha(new_name[0]))
        {
        new_name[0] = std::toupper(new_name[0]);
        }
        else
        {
            name = "";
            return 1;
        }
        for(long unsigned int i = 1; i < new_name.length() ; ++i)
        {
            if (isalpha(new_name[i]))
            {
                new_name[i] = std::tolower(new_name[i]);
            }
            else
            {
                name = "";
                return 1;
            }
        }
        name = new_name;
        return 0;
    }
    return -1;
}


int shopkeeper::set_surname(std::string new_surname)
{
    if (!new_surname.empty())
    {
        if (isalpha(new_surname[0]))
        {
        new_surname[0] = std::toupper(new_surname[0]);
        }
        else
        {
            surname = "";
            return 1;
        }
        for(long unsigned int i = 1; i < new_surname.length() ; ++i)
        {
            if (isalpha(new_surname[i]))
            {
                new_surname[i] = std::tolower(new_surname[i]);
            }
            else
            {
                surname = "";
                return 1;
            }
        }
        surname = new_surname;
        return 0;
    }
    return -1;
}


int shopkeeper::change_permission(int change, bool absolute)
{
    int max_lvl = 10, min_lvl = 0;
    if(absolute)
    {
        if(change>max_lvl || change<min_lvl)
        {
            return -1;
        }
        else
        {
            permission = change;
            return 0;
        }
    }
    else
    {
        if(permission+change>max_lvl || permission+change<min_lvl)
        {
            return -1;
        }
        else
        {
            permission += change;
            return 0;
        }
    }
}


int shopkeeper::change_experience(int change, bool absolute)
{
    if(absolute)
    {
        if(change<0)
        {
            return -1;
        }
        else
        {
            experience = change;
            return 0;
        }
    }
    else
    {
        if(experience+change<0)
        {
            return -1;
        }
        else
        {
            experience += change;
            return 0;
        }
    }
}


int shopkeeper::set_salary(int new_salary)
{
    if(new_salary<0)
    {
        return -1;
    }
    else
    {
        salary = new_salary;
        return 0;
    }
}


void shopkeeper::add_department(std::string department)
{
    departments.push_back(department);
}


void shopkeeper::rm_department(std::string department)
{
    for(auto i = departments.begin(); i!=departments.end(); ++i)
    {
        if(department == *i)
        {
            departments.erase(i);
        }
    }
}


void shopkeeper::rm_all_departments()
{
    departments.clear();
}


bool shopkeeper::operator!=(const shopkeeper &sk) const
{
    if(this == &sk)
    {
        return false;
    }
    else
    {
        return true;
    }
}


bool shopkeeper::operator==(const shopkeeper &sk) const
{
    if(name == sk.name || surname == sk.surname)
    {
        return true;
    }
    else
    {
        return false;
    }
}


shopkeeper& shopkeeper::operator=(const shopkeeper& sh)
{
    name = sh.name;
    surname = sh.surname;
    permission = sh.permission;
    salary = sh.salary;
    experience = sh.experience;
    rm_all_departments();
    for(auto i = sh.departments.begin(); i!=sh.departments.end(); ++i)
    {
        add_department(*i);
    }
    return *this;
}


std::ostream& operator<<(std::ostream &os,shopkeeper &sk)
{
    std::string the_departments = *sk.departments.begin();
    for(auto i = sk.departments.begin()+1; i!=sk.departments.end(); ++i)
    {
        the_departments += *i;
    }
    os<<"Name and surname: "<<sk.name<<" "<<sk.surname<<"\nPermission level: "<<sk.permission<<"\nExperience: "
    <<sk.experience<<" days"<<"\nSalary: "<<sk.salary<<" PLN"<<"\nAssigned departments: "<<the_departments<<"\n";
    return os;
}