#include "headers/transaction.h"

Transaction::Transaction(std::string transaction_id, std::string from_account_id, std::string to_account_id, int amount){
    this->transaction_id = transaction_id;
    this->from_account_id = from_account_id;
    this->to_account_id = to_account_id;
    this->amount = amount;
};
