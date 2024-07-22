#include "headers/account.h"

#include <string>
#include <random>
#include <ctime>

std::string Account::GetID(){
    return this->account_id;
}
Account::Account(std::string owner_name, double balance){
    this->account_id = GenerateID();
    this->owner_name = owner_name;
    this->balance = balance;
};

double Account::GetBalance(){
    
    return this->balance;
};

void Account::SetBalance(double new_balance){
    std::unique_lock<std::mutex> lock(this->mtx);
    this->balance = new_balance;
    lock.unlock();
};



std::string Account::GenerateID() {
    const std::string allowed_characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::string generatedId;
    
    std::mt19937 generator(static_cast<unsigned long>(std::time(nullptr)));
    
    std::uniform_int_distribution<> distribution(0, allowed_characters.size() - 1);
    
    for (size_t i = 0; i < 12; ++i) {
        generatedId += allowed_characters[distribution(generator)];
    }
    
    return generatedId;
}