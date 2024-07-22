#include <iostream>
#include <cstdio> 
#include "headers/processor.h"

int main(){
    Processor p ;
    Account* account_1 = p.CreateAccount("Mikhail Bulgakov", 1000.50);
    Account* account_2 = p.CreateAccount("Mary Shelley", 5000);

    std::printf("\naccount 1  balance: %f\n",p.AccountBalance(account_1));
    std::printf("account 2  balance: %f\n\n",p.AccountBalance(account_2));

    std::printf("sending 2378 from account 2 to account 1\n");

    bool result = p.ProcessTransaction(account_2, account_1, 2378);

    std::printf("Transaction should succeed: %d\n\n",result);

    std::printf("account 1  new balance: %f\n",p.AccountBalance(account_1));
    std::printf("account 2  new balance: %f\n\n",p.AccountBalance(account_2));


    std::printf("sending 4000 from account 1 to account 2\n");

    result = p.ProcessTransaction(account_1, account_2, 4000);

    std::printf("transaction should fail: %d\n\n",result);
    
    return 0;
} 