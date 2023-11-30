#ifndef REGISTRATION_H
#define REGISTRATION_H
#include <iostream>
#include <string>


class userRegistration{
    public:
        void registerUser(){
            std::string username, password;

            std::cout << "Enter username: ";
            std::cin >> username;
            std::ofstream a_file("usernames.dat", std::ios::app);
            a_file << username << std::endl;


            std::cout << "Enter password: ";
            std::cin >> password;
            std::ofstream b_file("passwords.dat", std::ios::app);
            b_file << password << std::endl;


            
        }
       
};

#endif