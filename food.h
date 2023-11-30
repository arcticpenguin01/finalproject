#include<iostream>
using namespace std;

class Food{

    public:
        Food( int calorie=0, string food= "Food"){
           if ( calorie >= 0){           
                caloriePerServing = calorie;
            }
            foodName = food;
        }
    // Food class
        Food operator+=(Food food);
    
        friend std::ostream& operator<<(std::ostream&, const Food&);
        friend std::istream& operator>>(std::istream&, Food&);

        void printCalorie();
        Food getCalorie(){
            return caloriePerServing;
        }

    private:
        int caloriePerServing;
        string foodName;
};


Food Food::operator+=(Food food){// overloaded function to add type Food together
    return caloriePerServing+=food.caloriePerServing;
}

void Food::printCalorie(){
    cout<<caloriePerServing;
}
ostream& operator<<(ostream& os,const Food& food){//cin and get operators being overloaded
    os<< food.foodName<<": "<<food.caloriePerServing<<endl;
    return os;
}

istream& operator>>(istream& is, const Food& food){
    is>>food;
    return is;
}



