#include <iostream>
#include <string>
#include <fstream>

bool is_first = 1;
char mode;
double X;
double Y;

bool discriminationYN()
{
    char XY;
    std::cin>>XY;
    if(XY != 'Y' && XY != 'y' && XY != 'N' && XY != 'n'){std::cout<<"whoops! Somethig went wrong..."<<std::endl; discriminationYN();}
    if(XY == 'Y' || XY == 'y'){return 1;}
    if(XY == 'N' || XY == 'n'){return 0;}
}

double calclation(char a,double b,double c)
{
    double original_b = b;
    switch (a)
        {
        case '+' : b = b + c; break;
        case '-' : b = b - c; break;
        case '*' : b = b * c; break;
        case '/' : b = b / c; break;
        case '^' : if(c > 0){while(c > 1){b = b * original_b; c--;}}
                   if(c == 0){b = 1;}
                   if(c < 0){while(c < 0){b = 1 / original_b; c++;}}
                   break;
        case 'P' : if(b == 0 || c == 0){b = 1;}
                   for(;c > 1;c--){b = b * --original_b;}
                   break;
        }
    return b;
}

void aaa()
{        
    std::cout<<"Lets select mode of calclation...   + - * / ^ x\"P\"y"<<std::endl;std::cin>>mode;
    for(;mode != '+' && mode != '-' && mode != '*' && mode != '/' && mode != '^' && mode !='P';)
        {
                std::cout<<"whoops! Somethig went wrong... select from + - * / ^ x\"P\"y"<<std::endl;
                std::cin>>mode;
        }
}

int main()
{
    if(is_first == 1)
        {
            std::cout<<"Calclator created by Ryota"<<std::endl; is_first = 0;
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
    std::cout<<"Do you want to continue calclation? Y/N ";
    if(discriminationYN() == 1)
        {
        main();
        }
        else
        {
    std::cout<<"Do you want to save the result? Y/N ";
    if(discriminationYN() == 1)
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

}