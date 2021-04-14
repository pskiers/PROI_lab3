#include <iostream>
#include "shopkeeper.h"
#include <string>
#include "test_thing.h"


int main()
{
    shopkeeper adam("adam", "nowak"), krzys("krzys", "kowalski"), hollow;
    bool RUN = true;
    int mode = 0;
    std::string input_msg, available = "Available objects: adam, krzys, hollow_guy\n",
        helpNwelcome = "This is a testing programme for class 'shopkeeper'\n";
    while (RUN)
    {
        std::cout<<helpNwelcome<<"With what object do you want to interact? To end programme enter 'exit'\n"<<available;
        std::cin>>input_msg;
        if(input_msg == "adam") mode = 1;
        else if(input_msg == "krzys") mode = 2;
        else if(input_msg == "hollow_guy") mode = 3;
        else if(input_msg == "exit") break;
        else mode = 0;

        std::string can_do = "You can:\n\tset_his_name\n\tset_his_surname\n\tset_his_salary\n\tchange_his_permission_level\n\tchange_his_experience\n\tadd_departmen_to_him\n\tremove_one_of_his_departments\n\tremove_all_of_his_departments\n\tcompare_with_some1\n\tprint_him_out\n\tget_his_name\n\tget_his_surname\n\tget_his_salary\n\tget_his_permission_level\n\tget_his_experience\n\tget_his_departments\n";
        std::cout<<"What do you want to do with him? "<<can_do;
        std::cin>>input_msg;
        if (input_msg == "compare_with_some1")
        {
            shopkeeper with_who;
            std::cout<<"With who do you want to comapre him?\n";
            std::cin>>input_msg;
            if(input_msg == "adam") with_who = adam;
            else if(input_msg == "krzys") with_who = krzys;
            else if(input_msg == "hollow_guy") with_who = hollow;
            else
            {
                std::cout<<"Bad object chosen\n";
                continue;
            }
            bool eq;
            std::cout<<"'==' or '!=' ?\n";
            std::cin>>input_msg;
            if(input_msg == "==") eq = true;
            else if(input_msg == "!=") eq = false;
            else
            {
                std::cout<<"U messed up\n";
                continue;
            }
            bool comp;
            switch (mode)
            {
            case 1:
                if(eq) comp = (adam == with_who);
                else comp = (adam != with_who);
                std::cout<<comp<<"\n";
                break;
            case 2:
                if(eq) comp = (krzys == with_who);
                else comp = (krzys != with_who);
                std::cout<<comp<<"\n";
                break;
            case 3:
                if(eq) comp = (hollow == with_who);
                else comp = (hollow != with_who);
                std::cout<<comp<<"\n";
                break;
            case 0:
                std::cout<<"Bad object chosen\n";
                break;
            }
        }
        else
        {
            switch (mode)
            {
            case 1:
                do_smth(&adam, input_msg);
                break;
            case 2:
                do_smth(&krzys, input_msg);
                break;
            case 3:
                do_smth(&hollow, input_msg);
                break;
            case -1:
                RUN = false;
                break;
            case 0:
                std::cout<<"Bad object chosen\n";
                break;
            }
        }
    }
    return 0;
}

