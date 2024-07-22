#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "account.h"
#include <string>


class Processor {
    public:
       // Processor(); 
        /// @brief in the assessment doc return type is void, but I will return the account, because I need the info in it since I have no db to select from
        Account* CreateAccount(const std::string& owner_name, double initial_balance);
        double AccountBalance(Account* account);
        /// same as above comment,in the assessment doc,they pass from/to account ids, but since I can't reach account from account_id here,
        /// I will take reference to account. if we had a database we are accessing the ids would be fine
        bool ProcessTransaction(Account* from_account, Account* to_account, double amount);
        static std::string GenerateTxnID();

};


#endif //PROCESSOR_H