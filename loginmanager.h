#include <fstream>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

class loginManager{
    public:
        void createUserFile(string username);
        loginManager(){
            access = false;
        }
        
        void registerAgain(){
            userRegistration registration;
            registration.registerUser();
        }
        
        void login(){
                cout << "\nEnter your username: "<< endl;
                cin >> usernameAttempt;
                username = retrieveFile("usernames.dat");

                cout << "Enter your password: "<< endl;
                cin >> passwordAttempt;
                password = retrieveFile("passwords.dat");
            
                if(usernameAttempt == username && passwordAttempt == password){
                    cout << "Logged in successfully!";
                } else{
                    int register_or_login;
                    cout << "Type in 1 to try to login again or type 2 to register: ";
                    
                    while (!(cin >> register_or_login)){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                   try {
                    switch(register_or_login){
                        case 1:
                            login();
                            break;
                        case 2:
                            registerAgain();
                            break;
                        default:
                            throw std::invalid_argument("Invalid input. Enter the number 1 or 2: ");
                    }
                      
                   } catch (const invalid_argument& e) {
                        cerr << e.what() << endl;
                    }
                } 
        }
        
        void grantAccess(string username, string password){
            if(username == usernameAttempt && password == passwordAttempt){
                access = true;
                cout << "Access granted!" << endl;
                createUserFile(username);
                ofstream outfile(username + ".txt");

            } else{
                cout << "Access denied!" << endl;
            }
        }
        
        bool hasAccess(){
            return access;
        }
        
        string retrieveFile(const char* userFile){
            string userInfo;
            fstream file;

            file.open(userFile, ios::in);
            if (file.is_open()){
                getline(file, userInfo);
            }
            file.close();
            return userInfo;
        }
    
    private:
        string username;
        string password;
        string usernameAttempt;
        string passwordAttempt;
        bool access;

};


void loginManager::createUserFile(string username) {
    string filename = username + ".txt";
    ofstream outfile(filename);
    outfile << "This is " << username << "'s file." << endl;
    outfile.close();
}
