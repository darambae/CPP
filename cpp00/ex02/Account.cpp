/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:22:08 by dabae             #+#    #+#             */
/*   Updated: 2024/07/18 17:25:34 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int  Account::getNbAccounts()
{
    return _nbAccounts;
}

int  Account::getTotalAmount()
{
    return _totalAmount;
}

int  Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int  Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

void  Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalAmount << std::endl;
}

void	Account::makeDeposit(int deposit)
{
    if (deposit > 0)
    {
        _nbDeposits++;
        _totalNbDeposits++;
        _amount += deposit;
    }
}

bool	Account::makeWithdrawal(int withdrawal)
{
    if (checkAmount() > withdrawal && withdrawal > 0)
    {
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;
        std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
        _amount -= withdrawal;
        std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    }
    else
    {
        std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
        return false;
    }
        
}

int		Account::checkAmount(void) const
{
    return _amount;
}

void	Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void    Account::_displayTimestamp()
{
    std::time_t cur_time;
    tm * curr_time;
    char time_stamp[100];
    
    time(&cur_time);
    curr_time = localtime(&cur_time);
    strftime(time_stamp, 50, "[%Y%m%d_%H%M%S]", curr_time);
    std::cout << time_stamp;
}
Account::Account(void) {}

Account::Account (int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;

}

Account::~Account ()
{
    for (int i = 0; i < _nbAccounts; i++)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
    }
}