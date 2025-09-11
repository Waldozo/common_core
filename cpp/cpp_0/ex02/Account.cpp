#include "Account.hpp"
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
    std::cout << "[19920104_091532]";
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
    int p_amount = _amount; // 1. Sauvegarder l'ancien montant

    _amount += deposit;      // 2. Ajouter le dépôt au compte
    _nbDeposits++;           // 3. Incrémenter les dépôts de ce compte
    _totalAmount += deposit; // 4. Mettre à jour le total global
    _totalNbDeposits++;      // 5. Incrémenter le total des dépôts

    _displayTimestamp(); // 6. Afficher le timestamp
    std::cout << " index:" << _accountIndex
              << ";p_amount:" << p_amount
              << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    int p_amount = _amount;


    _displayTimestamp();
    if (_amount >= withdrawal)
    {

        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        std::cout << " index:" << _accountIndex
                  << ";p_amount:" << p_amount
                  << ";withdrawal:" << withdrawal
                  << ";amount:" << _amount
                  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    }
    else if (_amount < withdrawal)
    {
        std::cout << " index:" << _accountIndex
                  << ";p_amount:" << p_amount
                  << ";withdrawal:" << "refused" << std::endl;
        return (false);
    }
    return(true);
}