/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:49:59 by dabae             #+#    #+#             */
/*   Updated: 2024/08/20 17:40:23 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange(){
	dataToList();
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange(){}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

bool	dateValidity(const std::string& date)
{
	if (std::stoi(date.substr(5, 6)) > 12 || std::stoi(date.substr(8, 9)) > 31)
		return false;
	return true;
}

bool	valueValidity(const float& value)
{
	if (value < 0 || value > 1000)
		return false;
	return true;
}

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if ( this != &rhs )
	{
		this->_data = rhs._data;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

// CompareFirst is a functor that compares the first element of a pair with a key (only to use with std::find_if)
struct CompareFirst {
    CompareFirst(const std::string& key) : _key(key) {}

    bool operator()(const std::pair<std::string, float>& pair) const {
        return pair.first == _key;
    }

	private:
		std::string _key;
};

/* Transform csv file to list with key value pair */
void	BitcoinExchange::dataToList()
{
	std::ifstream csvFile;
	csvFile.open("data.csv");
	if (!csvFile.is_open())
	{
		std::cerr << "Error: File not found" << std::endl;
		return;
	}
	std::string line;
	std::string key;
	std::string value;
	while (std::getline(csvFile, line))
	{
		if (std::isalpha(line[0]) == true)
			continue;
		key = line.substr(0, 10);
		value = line.substr(line.find(',') + 1);
		try
		{
			_data.push_back(std::pair<std::string, float>(key, std::stof(value)));
		}
		catch(const std::exception& e)
		{
			_data.push_back(std::pair<std::string, float>(key, std::numeric_limits<float>::quiet_NaN()));
		}
	}
}
/*Read through input file and search through the data list */
void	BitcoinExchange::printResult( const std::string& filename )
{
	std::list<std::pair<std::string, float> >::iterator itData;
	std::ifstream inputFile;
	inputFile.open(filename);
	if (!inputFile.is_open())
	{
		std::cerr << "Error: File not found" << std::endl;
		return;
	}
	std::string line;
	std::string key;
	float value;
	while (std::getline(inputFile, line))
	{
		if (std::isalpha(line[0]) == true)
			continue;
		if (line.find('|') == std::string::npos || line[4] != '-' || line[7] != '-')
		{
			std::cerr << "Error: Invalid format => " << line << std::endl;
			continue;
		}
		key = line.substr(0, line.find('|'));
		if (dateValidity(key) == false)
		{
			std::cerr << "Error: Invalid date => " << key << std::endl;
			continue;
		}
		try
		{
			value = std::stof(line.substr(line.find('|') + 1));
			if (valueValidity(value) == false)
			{
				std::cerr << "Error: Invalid value => " << line.substr(line.find('|') + 1) << std::endl;
				continue;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: Invalid value => " << line.substr(line.find('|') + 1) << std::endl;
			continue;
		}
		itData = std::find_if(_data.begin(), _data.end(), CompareFirst(key));
		std::string closestDate;
		if (itData == _data.end())
		{
			closestDate = findClosestDate(key);
			itData = std::find_if(_data.begin(), _data.end(), CompareFirst(closestDate));
		}
		std::cout << key << " => " << value << " = " << value * itData->second << std::endl;
	}
}	

std::string	BitcoinExchange::findClosestDate(const std::string& date)
{
	std::string closestDate;
	std::list<std::pair<std::string, float> >::iterator it;
	
	for (it = _data.begin(); it != _data.end(); it++)
	{
		if (it->first < date)
			closestDate = it->first;
	}
	if (closestDate == "")
		closestDate = _data.begin()->first;
	return closestDate;
}

/* ************************************************************************** */