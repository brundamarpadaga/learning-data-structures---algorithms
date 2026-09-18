/* Problem: Bank Transfer

Two bank accounts, two threads transferring money between them simultaneously.


Thread 1: transfer from Account A → Account B
Thread 2: transfer from Account B → Account A
Each transfer locks the source account, then tries to lock the destination. With the wrong lock order, they deadlock.

Phase 1: Write it so it deadlocks (should be easy)
Phase 2: Fix it with std::scoped_lock (locks both atomically, no deadlock) */

#include<string>
#include<iostream>
#include<thread>
#include<mutex>

static int some_number = 127564031;
class Account{

    public:
    std::mutex mtx;
    Account(std::string name): name(name){
        account_number = ++some_number;
        balance = 100;
        std::cout << "Account created with number: " << account_number << std::endl;
    }

    void deposit(int amount){
        if(amount < 0){
            return;
        }
        this->balance += amount;
    }

    void withdraw(int amount){
        if(amount < 0){
            return;
        }
        this->balance -= amount;
    }
    void print_balance(){
        std::cout << "Account number: " << account_number << ", Name: " << name << ", Balance: " << balance << std::endl;
    }
    int get_account_number(){
        return account_number;
    }
    std::string get_name(){
        return name;
    }
    
    private:
    
    int account_number;
    std::string name;
    int balance;
};


void transfer(Account& account1, Account& account2, int amount){
    std::unique_lock<std::mutex> lock1(account1.mtx);  // lock both accounts 
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // force interleaving
    std::unique_lock<std::mutex> lock2(account2.mtx);
    account1.withdraw(amount);
    account2.deposit(amount);
    
    lock1.unlock();
    lock2.unlock();
    std::cout << "Transferred " << amount << " from account " << account1.get_name() << " to account " << account2.get_name()  << std::endl;

}

int main(){
    Account account1("Alice");
    Account account2("Bob");

    std::cout << "Before transfer:" << std::endl;
    account1.print_balance();
    account2.print_balance();

    std::thread transfer1(transfer, std::ref(account1), std::ref(account2), 50);
    std::thread transfer2(transfer, std::ref(account2), std::ref(account1), 30);

    
    transfer1.join();
    transfer2.join();

    std::cout << "After transfer:" << std::endl;
    account1.print_balance();
    account2.print_balance();
}