#include<iostream>
#include<random>
#include<string>
#include<chrono>
using namespace std;

string Card(int value, int suit){
    string num[]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    string sym[]={"S","H","C","D"};
    return num[value-1]+sym[suit];
}

int sum(int SumNum){
    if (SumNum>=10)
    {
        return 10;
    }else if (SumNum==1)
    {
        return 11;
    }else{
        return SumNum;
    } 
}

int main(){
    unsigned random=chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen (random);
    uniform_int_distribution<> Numdist(1,13);
    uniform_int_distribution<> Suitdist(0,3);

    int PlayerNum1=Numdist(gen);
    int DealerNum1=Numdist(gen);
    int PlayerSuit1=Suitdist(gen);
    int DealerSuit1=Suitdist(gen);
    int PlayerNum2=Numdist(gen);
    int DealerNum2=Numdist(gen);
    int PlayerSuit2=Suitdist(gen);
    int DealerSuit2=Suitdist(gen);
    int PSum=sum(PlayerNum1)+sum(PlayerNum2);
    int DSum=sum(DealerNum1)+sum(DealerNum2);
    int DAce=(DealerNum1==1)+(DealerNum2==1);

    int PAce=0;
    if (PlayerNum1==1)
    {
        PAce++;
    }if (PlayerNum2==1)
    {
        PAce++;
    } 
    
    string input;
    string hit="Hit";
    string stand="Stand";
    string PCard1=Card(PlayerNum1,PlayerSuit1);
    string DCard1=Card(DealerNum1,DealerSuit1);
    string PCard2=Card(PlayerNum2,PlayerSuit2); 
    string DCard2=Card(DealerNum2,DealerSuit2); 

    cout<<"Your cards are: "<<PCard1<<" And "<<PCard2<<"\n";
    cout<<"Dealer's first card is: "<<DCard1<<"\n";

    while (true)
    {
        if (PSum==21)
    {
        cout<<"Blackjack!!!!";
        break;
    }

        cout<<"Hit or Stand?"<<"\n";
        cin>>input;
        if (input==hit)
    {
        int RandomNum=Numdist(gen);
        int RandomSuit=Suitdist(gen);
        cout<<"Your next card is: "<<Card(RandomNum,RandomSuit)<<"\n";
        PSum += sum(RandomNum);

        if (RandomNum==1)
        {
            PAce++;
        }
        while (PSum>21 && PAce>0)
        {
            PSum -= 10;
            PAce--;
        }

        cout<<"Your total now is: "<<PSum<<"\n";
        if (PSum==21)
        {
            cout<<"Blackjack!!!";
            break;
        }else if (PSum>21)
        {
            cout<<"You Lose";
            break;
        }
    }else if (input==stand)
        {
            cout<<"Your total sum now is: "<<PSum<<"\n";
            cout<<"Dealer's Second card is: "<<DCard2<<"\n";

            while (DSum<17)
                {
                    int DRandomNum=Numdist(gen);
                    int DRandomSuit=Suitdist(gen);
                    cout<<"Dealer's next card is: "<<Card(DRandomNum,DRandomSuit)<<"\n";
                    DSum += sum(DRandomNum);

                    if (DRandomNum==1){
                        DAce++;
                    }
                    while (DSum>21 && DAce>0)
                    {
                        DSum -=10;
                        DAce--;
                    }
                    
                }
                
                    if (DSum<=PSum)
                {
                    cout<<"The dealer's total sum is: "<<DSum<<"\n";
                    cout<<"YOU WIN!!!!";
                }
                    else if (DSum>PSum && DSum<21)
                {
                    cout<<"The dealer's total sum is: "<<DSum<<"\n";
                    cout<<"You Lose";
                    break;
                }
                
                break;
                }
    }

    return 0;
}