/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:37:23 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/06/16 19:50:47 by jaiveca-         ###   ########.fr       */
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
}

Account::~Account(void)
{
	
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
				<< "withdrawals:" << getNbWithdrawals() << ";"
				<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
				<< "p_amount:" << checkAmount() << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << checkAmount() + deposit << ";"
				<< "nb_deposits:" << this->_nbDeposits << ";"
				<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	return true;
}

int Account::checkAmount(void) const
{
	return (this->_amount);
}

void Account::displayStatus(void) const
{
	
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