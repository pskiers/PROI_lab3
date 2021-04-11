#ifndef SHOPKEEPER_H
#define SHOPKEEPER_H

#include <string>
#include <vector>

class shopkeeper
{
private:
    std::string name, surname;
    int permission, experience, salary;
    std::vector <std::string> departments;
public:
    shopkeeper(std::string name="", std::string surname=""){
        set_name(name);
        set_surname(surname);
        permission = experience = salary = 0;
    };
    std::string get_name() const {return name;}
    int set_name(std::string new_name);
    std::string get_surname() const {return surname;}
    int set_surname(std::string new_surname);
    int get_permission() const {return permission;}
    int change_permission(int change, bool absolute);
    int get_experionce() const {return experience;}
    int change_experience(int change, bool absolute);
    int get_salary() const {return salary;}
    int set_salary(int new_salary);
    std::vector <std::string> get_departments(){return departments;}
    void add_department(std::string department);
    void rm_department(std::string department);
};
#endif