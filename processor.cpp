#include "headers/processor.h"
#include "headers/transaction.h"
//#include "headers/account.h"
#include <random>


Account* Processor::CreateAccount(const std::string& owner_name, double initial_balance){
        return new Account(owner_name, initial_balance);
};


 double Processor::AccountBalance(Account* account){
    return account-> GetBalance();
 }


 bool Processor::ProcessTransaction(Account* from_account, Account* to_account, double amount){
    double b = from_account ->GetBalance();
    if (b<amount){
        return false;
    }
    double new_to_balance = to_account ->GetBalance() + amount;
    double new_from_balance = b - amount;
    from_account->SetBalance(new_from_balance);
    to_account->SetBalance(new_to_balance);
    std::string txnid = Processor::GenerateTxnID();

    //// creating transaction on heap, ideally this would be inserted in DB, we could also return the address of transaction
    new Transaction(txnid, from_account->GetID(), to_account->GetID(), amount);
    return true;
 }


 std::string Processor::GenerateTxnID() {
    const std::string allowed_characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::string generatedId;
    
    std::mt19937 generator(static_cast<unsigned long>(std::time(nullptr)));
    
    std::uniform_int_distribution<> distribution(0, allowed_characters.size() - 1);
    
    for (size_t i = 0; i < 24; ++i) {
        generatedId += allowed_characters[distribution(generator)];
    }
    
    return generatedId;
}