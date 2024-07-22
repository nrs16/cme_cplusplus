#ifndef TRANSACTION_H
#define TRANSACTION_H


#include <string>


class Transaction {
    private:
        std::string transaction_id;
        std::string from_account_id;
        std::string to_account_id;
        int amount;    
    public:
        Transaction(std::string transaction_id, std::string from_account_id, std::string to_account_id, int amount); 
        static std::string GenerateTxnID(int length);

};


#endif //TRANSACTION_H