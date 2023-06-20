/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:37:23 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/06/20 00:41:18 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_nbAccounts++;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = _nbAccounts - 1;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
				<< "amount:" << checkAmount() << ";"
				<< "created" << std::endl;	
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
				<< "amount:" << checkAmount() << ";"
				<< "closed" << std::endl;		
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return(_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return(_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
				<< "total:" << getTotalAmount() << ";"
				<< "deposits:" << getNbDeposits() << ";"
				<< "withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
				<< "p_amount:" << checkAmount() << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << checkAmount() + deposit << ";"
				<< "nb_deposits:" << this->_nbDeposits
				<< std::endl;
	this->_amount += deposit;
	_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (withdrawal > checkAmount())
	{
		std::cout << "index:" << this->_accountIndex << ";"
					<< "p_amount:" << checkAmount() << ";"
					<< "withdrawal:refused"
					<< std::endl;	
		return (false);	
	}
	else
	{
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << "index:" << this->_accountIndex << ";"
					<< "p_amount:" << checkAmount() << ";"
					<< "withdrawal:" << withdrawal << ";"
					<< "amount:" << checkAmount() - withdrawal << ";"
					<< "nb_withdrawals:" << this->_nbWithdrawals
					<< std::endl;
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		return (true);
	}
}

int Account::checkAmount(void) const
{
	return (this->_amount);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
				<< "amount:" << checkAmount() << ";"
				<< "deposits:" << this->_nbDeposits << ";"
				<< "withdrawals:" << this->_nbWithdrawals
				<< std::endl;		
}

void Account::_displayTimestamp(void)
{
	time_t		rawtime;
	struct tm	*timeinfo;
	
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	std::cout << "[" << timeinfo->tm_year + 1900 
			<< std::setfill('0') << std::setw(2) << timeinfo->tm_mon + 1
			<< std::setfill('0') << std::setw(2) << timeinfo->tm_mday << "_"
			<< std::setfill('0') << std::setw(2) << timeinfo->tm_hour
			<< std::setfill('0') << std::setw(2) << timeinfo->tm_min
			<< std::setfill('0') << std::setw(2) << timeinfo->tm_sec << "] ";		
}