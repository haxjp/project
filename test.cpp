#include <iostream>
#include <string>
#include <fstream>

bool is_first = true;
char mode;
double X;
double Y;

bool discriminationYN()
{
    char XY;
    std::cin>>XY;
    if(XY != 'Y' && XY != 'y' && XY != 'N' && XY != 'n'){std::cout<<"whoops! Somethig went wrong..."<<std::endl; discriminationYN();}
    if(XY == 'Y' || XY == 'y'){return true;}
    if(XY == 'N' || XY == 'n'){return false;}
}

double calclation(char a,double b,double c){
    double original_b = b;
    switch (a)
        {
        case '+' : b = b + c; break;
        case '-' : b = b - c; break;
        case '*' : b = b * c; break;
        case '/' : b = b / c; break;
        case '^' :
                if(c > 0){while(c > 1){b = b * original_b; c--;}}
                if(c == 0){b = 1;}
                if(c < 0){while(c < 0){b = 1 / original_b; c++;}}
                break;
        }
    return b;
}

void aaa(){        std::cout<<"Lets select mode of calclation...   + - * / ^"<<std::endl;std::cin>>mode;
        for(;mode != '+' && mode != '-' && mode != '*' && mode != '/' && mode != '^';)
            {
                std::cout<<"whoops! Somethig went wrong... select from + - * / ^"<<std::endl;
                std::cin>>mode;
            }
        }

int main(){
    if(is_first==true)
        {
            std::cout<<"Calclator created by Ryota"<<std::endl; is_first = false;
        }
    std::cout<<"Please show me the numbers for calclation... like X + Y"<<std::endl;
    std::cout<<"X=";std::cin>>X;
    std::cout<<"Y=";std::cin>>Y;
    aaa();
    if(Y == 0 && mode == '/')
        {
        std::cout<<"Division by 0 is not allowed, Change the number other than 0 or change the mode "<<std::endl;
        std::cout<<"Y=";std::cin>>Y;
        aaa();
        }
    double result = calclation(mode,X,Y);
    std::cout<<"result is " << result <<std::endl;
    std::cout<<"Do you want to save the result? Y/N ";
    if(discriminationYN() == true)
        {
        std::ofstream create_and_write;
        create_and_write.open("result.txt");
        create_and_write << result;
        create_and_write.close();}
        else
        {
        return 0;
        }
}