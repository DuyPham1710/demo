#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Bank;

class Account{
private: 
    string name;
    int balance;
public:
    string get_name(){
        return this->name;
    }

    int get_balance(){
        return this->balance;
    }

    friend Bank;
};

class Bank{
private:
    vector<Account> accounts;
public:
    void add_account(string name, int balance){
        Account tmp;
        tmp.name = name;
        tmp.balance = balance;
        this->accounts.push_back(tmp);
    }

    void get_account(string name){
        int index = -1;
        for(int i=0; i<this->accounts.size(); i++)
            if(!name.compare(this->accounts[i].name))
                index = i;
        if(index != -1)
            cout << accounts[index].get_name() << " " << accounts[index].get_balance() << endl;
        else
            cout << "Not found !\n";
    }
};

int main(){
    Bank bank;
    bank.add_account("Vy", 2000);
    bank.add_account("Duy", 3000);
    bank.add_account("Lam", 4000);
    
    bank.get_account("Duy");

    return 0;
}
