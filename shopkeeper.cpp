#include "shopkeeper.h"
#include <string>
#include <vector>
#include <cctype>

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