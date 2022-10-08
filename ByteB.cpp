#include<conio.h>
#include<iostream>
#include<string>
using namespace std;

class atm{
    private:
        long int account_no;
        string name;
        int pin;
        double balance;
        string mobile_no;
    public:
        void setdata(long int account_no_a,string name_a,int pin_a,double balance_a,string mobile_no_a)
        {
            account_no=account_no_a;
            name=name_a;
            pin=pin_a;
            balance=balance_a;
            mobile_no=mobile_no_a;
        }
        string getname(){
            return name;
        }
        int getpin(){
            return pin;
        }
        double getbalance(){
            return balance;
        }
        string getmobileno(){
            return mobile_no;
        }
        long int getaccountno(){
            return account_no;
        }
        void setmobile(string mob_prev,string mob_new){
            if(mob_prev==mobile_no){
                mobile_no=mob_new;
                cout<<endl<<"successfully updated mobile no.";
                _getch();
            }
            else{
                cout<<endl<<"invalid old mobile no";
                _getch();
            }
        }
        void cashwithdraw(int amount_a){
            if(amount_a>0 && amount_a<balance){
                 balance-=amount_a;
                 cout<<endl<<"please collect your cash";
                 cout<<endl<<"available balance:"<<balance;
                 _getch();
            }
            else{
                cout<<endl<<"insufficient balance";
                _getch();
            }
        }

};

int main(){
    int choice=0,enterpin;
    long int enteraccountno;
    system("cls");
    atm user1;
    user1.setdata(1233664,"tim",1111,45000,"900053322");
    do{
        system("cls");
        cout<<endl<<"welcome"<<endl;
        cout<<endl<<"enter your account no";
        cin>>enteraccountno;
        cout<<endl<<"enter pin";
        cin>>enterpin;
        if((enteraccountno==user1.getaccountno()) && (enterpin==user1.getpin())){
            do{
                int amount=0;
                string oldmobno,newmobno;
                system("cls");
                cout<<endl<<"welcome"<<endl;
                cout<<endl<<"select options"<<endl;
                cout<<endl<<"1.check balance"<<endl;
                cout<<endl<<"2.cash withdraw"<<endl;
                cout<<endl<<"3.show user details"<<endl;
                cout<<endl<<"4.update mobile no"<<endl;
                cout<<endl<<"5.exit"<<endl;
                cin>>choice;
                switch (choice)
                {
                case 1:
                    /* code */
                    cout<<endl<<"your bank balance is"<<user1.getbalance();
                    _getch();
                    break;
                
                case 2:
                    /* code */
                    cout<<endl<<"enter the amount";
                    cin>>amount;
                    user1.cashwithdraw(amount);
                    break;
                
                case 3:
                    /* code */
                    cout<<endl<<"user details are";
                    cout<<endl<<"account no"<<user1.getaccountno();
                    cout<<endl<<"Name"<<user1.getname();
                    cout<<endl<<"balance"<<user1.getbalance();
                    cout<<endl<<"Mobile no"<<user1.getmobileno();
                    _getch();
                    break;

                case 4:
                    /* code */
                    cout<<endl<<"enter old mobile no.";
                    cin>>oldmobno;
                    cout<<endl<<"enter new mobile no";
                    cin>>newmobno;
                    user1.setmobile(oldmobno,newmobno);
                    break;

                case 5:
                    /* code */
                    exit(0);
                
                default:
                    cout<<endl<<"enter valid data";
                }
            }while(1);
        }
    }while(1);

    return 0;
}