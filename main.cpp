#include <iostream>
#include <fstream>
#include "registration.h"
#include "loginmanager.h"
#include "food.h"
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

string nameofFile;

Food chickenAlfredo{1570,"Chicken Alfredo"};
Food spaghettiAndMeatballs{680,"Spaghetti and Meatballs"};
Food tourOfItaly{1550,"Tour of Italy"};
// Appetizers
Food friedMozzarella{800,"Fried Mozzarella"};
Food stuffedZifiFritta{500,"Stuffed Ziti Fritta"};
// Drinks
Food raspberryLemondade{170,"Raspberry Lemonade"};
Food classicLemonade{170,"Classic Lemonda"};
// Dessert
Food blackTieMousseCake{750,"Black Tie Mouse Cake"};
Food strawberryCreamCake{470,"Strawberry Cream Cake"};

void displayMenu();

void foodSelect(string fileName){
    int userChoice;
    ofstream sampleCalorie;

    sampleCalorie.open(fileName, std::ios::app);
    sampleCalorie<<__DATE__<<" "<<__TIME__<<endl;// outputs time everytime the file is open
    Food total {0,"Total"};// variable that holds total amount of calories
    do{
        displayMenu();
        cout<< "Enter choice ";// switch case for users choice
        cin>> userChoice;
        switch(userChoice){
            case 1:
                total+=tourOfItaly;
                sampleCalorie<<tourOfItaly;
            case 2:
                total+=chickenAlfredo;
                sampleCalorie<<chickenAlfredo;
                break;
            case 3:
                total+=spaghettiAndMeatballs;
                sampleCalorie<<spaghettiAndMeatballs;
                break;
            case 4:
                total+=friedMozzarella;
                sampleCalorie<<friedMozzarella;
                break;
            case 5:
                total+=stuffedZifiFritta;
                sampleCalorie<<friedMozzarella;
                break;
            case 6:
                total+=raspberryLemondade;
                sampleCalorie<<raspberryLemondade;
                break;
            case 7:
                total+=classicLemonade;
                sampleCalorie<<classicLemonade;
                break;
            case 8:
                total+=blackTieMousseCake;
                sampleCalorie<<blackTieMousseCake;      
                 break;
            case 9:
                total+=strawberryCreamCake;
                sampleCalorie<<strawberryCreamCake;
                break;
            case 10: 
                cout << "*********** YOUR INFO HAS BEEN SUCCESSFULLY WRITEN TO YOUR PERSONAL FILE ***********";
                break;
            default:
                cout<<"Not an option"<<endl;
                break;
        }

        
    }
        while(userChoice != 10);
    
        sampleCalorie<< total<<endl;
        sampleCalorie.close();
}



void displayMenu(){//displays menu items
    cout<<setw(25)<<left<<"Entrees"
    <<setw(30)<<left<<"Appetizers"
    <<setw(30)<<left<<"Drinks"
    <<setw(25)<<"Dessert"<<right
    <<setw(20)<<"10. Exit"<<left<<endl;

    cout<<setw(25)<<left<<"1. Tour of Italy"
    <<setw(30)<<left<<"4. Fried Mozzarella"
    <<setw(30)<<left<<"6. Raspberry Lemonade"
    <<setw(25)<<"8. Black Tie Mousse Cake"<<left<<endl;

    cout<<setw(25)<<left<<"2. Chicken Alfredo"
    <<setw(30)<<left<<"5. Stuffed Ziti Fritta"
    <<setw(30)<<left<<"7. Classic Lemonade"
    <<setw(25)<<"9. Strawberry Cream Cake"<<left<<endl;

    cout<<setw(25)<<left<<"3. Spaghetti and Meatballs"<<endl;
     
}


void welcomeScreen(){
    cout << 
    R"(
    *********************************************
                    WELCOME                                  
               
    ********************************************* 
                    Menu                            
                
    Type in the number corresponding to your choice.
                
    1. REGISTER
    2. LOGIN
    3. DISPLAY MENU )";

    int options;
    cout << "\nMake your selection: ";
    while (!(cin >> options)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer: ";
    }


    try {
        switch (options) {
            case 1: {
                userRegistration user;
                user.registerUser();
                cout << "Successfully registered!\n";
                string nameofFile;
                cout << "Name your file: ";
                cin >> nameofFile;
                foodSelect(nameofFile + ".txt");
                break;
            }
            case 2: {
                loginManager userLogin;
                loginManager manager2;
                userLogin.login();
                manager2.grantAccess("username", "password");
                if (manager2.hasAccess()) {
                    string username;
                    cout << "Type in your username again to create a personal file: ";
                    cin >> username;
                    manager2.createUserFile(username);
                    displayMenu();
                    foodSelect(username + ".txt");
                }
                break;
            }
            case 3: {
                cout << "MENU: \n";
                displayMenu();
                break;
            }
            default:
                throw invalid_argument("Invalid input. Please enter an integer between 1 and 3.");
        }
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }
}


int main(){
    welcomeScreen();
    return 0;
}