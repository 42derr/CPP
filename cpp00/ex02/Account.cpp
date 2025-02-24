#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {

    _displayTimestamp();
	_nbDeposits = 0;
	_nbWithdrawals = 0;
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbAccounts++;

    std::cout << "index:" <<  _accountIndex << ";"
              << "amount:" << initial_deposit << ";"
              << "created" << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    _nbAccounts--;
    _totalAmount -= _amount;
    std::cout << "index:" <<  _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "closed" << std::endl;
}

void	Account::_displayTimestamp( void ) {
    std::time_t now = std::time(NULL);

    std::tm* localTime = std::localtime(&now);

    std::cout << "["
              << (localTime->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << localTime->tm_mday
              << "_"
              << std::setw(2) << std::setfill('0') << localTime->tm_hour
              << std::setw(2) << std::setfill('0') << localTime->tm_min
              << std::setw(2) << std::setfill('0') << localTime->tm_sec
              << "] ";
}

int	Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int	Account::getTotalAmount( void){
    return _totalAmount;
}

int	Account::getNbDeposits( void ){
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ){
    return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ){
    _displayTimestamp();
    std::cout << "accounts:" <<  _nbAccounts << ";"
              << "total:" << _totalAmount << ";"
              << "deposits:" << _totalNbDeposits << ";"
              << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ){
    _displayTimestamp();

    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;

    std::cout << "index:" <<  _accountIndex << ";"
              << "p_amount:" << _amount << ";";
    _amount += deposit;
    std::cout << "deposit:" << deposit << ";"
              << "amount:" << _amount << ";"
              << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
    _displayTimestamp();
    if (withdrawal > checkAmount())
    {
        std::cout << "index:" <<  _accountIndex << ";"
        << "p_amount:" << _amount << ";"
        << "withdrawal:refused" << std::endl;
        return false;
    }
    else
    {    
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;
    
        std::cout << "index:" <<  _accountIndex << ";"
                    << "p_amount:" << _amount << ";";
        _amount -= withdrawal;
        std::cout << "withdrawal:" << withdrawal << ";"
                    << "amount:" << _amount << ";"
                    << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    }
}

int		Account::checkAmount( void ) const{
    return _amount;
}

void	Account::displayStatus( void ) const{
    _displayTimestamp();
    std::cout << "index:" <<  _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "deposits:" << _nbDeposits << ";"
              << "withdrawals:" << _nbWithdrawals << std::endl;
}
