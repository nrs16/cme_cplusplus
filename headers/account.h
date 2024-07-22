#ifndef ACCOUNT_H
#define ACCOUNT_H


#include <string>
#include <mutex>

class Account {
    private:
        std::string account_id;
        std::string owner_name;
        double balance;
        /// will use the mutex to organize reads and writes on the balance
        mutable std::mutex mtx;

    public:
        Account(std::string owner_name, double balance); 
        std::string GetID();
        double GetBalance();
        void SetBalance(double);
        static std::string GenerateID();

};


#endif // ACCOUNT_H