#include<iostream>
#include<random>
#include<string>
#include<chrono>
using namespace std;

string card(int value,int suit){
    string num[]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    string Sym[]={"S","H","D","C"};
    return num[value-1]+Sym[suit];
}

int main(){
    unsigned rd=chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen (rd);
    uniform_int_distribution<> Numdist(1,13);
    uniform_int_distribution<> Suitdist(0,3);


    int num1=Numdist(gen);
    int suit1=Suitdist(gen);
    int num2=Numdist(gen);
    int suit2=Suitdist(gen);
    string input;
    string Low="Low";
    string High="High";
    string Equal="Equal";

    string Card1=card(num1,suit1);
    string Card2=card(num2,suit2);
    
    cout<<"First number is "<<Card1<<"\n";
    cout<<"Guess the next number "<<"\n";
    cin>>input;

    if (num2>num1 && input==High)
    {
        cout<<Card2<<"\n";
        cout<<"You guessed correct";
    }else if(num2<num1 && input==Low){
        cout<<Card2<<"\n";
        cout<<"You guessed correct";
    }else if(num2==num1 && input==Equal){
        cout<<Card2<<"\n";
        cout<<"You guessed correct";
    }else{
        cout<<Card2<<"\n";
        cout<<"You guessed wrong";
    }
    
    return 0;
}