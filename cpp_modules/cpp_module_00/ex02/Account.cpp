#include <iostream>
#include <iomanip>
#include <ctime>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << Account::_totalAmount
		<< ";deposits:" << Account::_totalNbDeposits
		<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
: _accountIndex(_nbAccounts)
, _amount(initial_deposit)
, _nbDeposits(0)
, _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
		<< _amount << ";created" << std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
		<< _amount << ";closed" << std::endl;
	Account::_nbAccounts--;
	Account::_totalAmount -= _amount;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount + deposit
		<< ";nb_deposits:" << _nbWithdrawals + 1 << std::endl;
	_amount += deposit;
	_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";withdrawal:refused" << std::endl;
		return false;
	}
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << _amount - withdrawal
		<< ";nb_withdrawals:" << _nbWithdrawals + 1 << std::endl;
	_amount -= withdrawal;
	_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return true;
}

int		Account::checkAmount(void) const
{
	return _amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t time = std::time(0);
	std::tm *now = std::localtime(&time);

	std::cout << std::put_time(now, "[%Y%m%d_%H%M%S] ");
}

Account::Account(void) {}
