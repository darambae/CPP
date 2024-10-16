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
	char *end;

	int	year = std::strtol(date.substr(0, 4).c_str(), &end, 10);
	int month = std::strtol(date.substr(5, 6).c_str(), &end, 10);
	int day = std::strtol(date.substr(8, 9).c_str(), &end, 10);

	if (year < 0 || month > 12 || day > 31)
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

// Since list doesn't provide a built-in mechanisms for searching by key, here I made a functor to mimic the behavior of std::find()
// struct CompareFirst {
//     CompareFirst(const std::string& key) : _key(key) {}

//     bool operator()(const std::pair<std::string, float>& pair) const {
//         return pair.first == _key;
//     }

// 	private:
// 		std::string _key;
// };

/* Transform csv file to list/map with key value pair */
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
		if (std::isalpha(line.c_str()[0]))
			continue;
		key = line.substr(0, 10);
		value = line.substr(line.find(',') + 1);

		char *end;
		float floatValue = std::strtof(value.c_str(), &end);
		if (*end)
			floatValue = 0.0 / 0.0; //assigning NaN
		_data[key] = floatValue;
		//_data.push_back(std::pair<std::string, float>(key, floatValue));
	}
}
/*Read through input file and search through the data list/map */
void	BitcoinExchange::printResult( const std::string& filename )
{
	//std::list<std::pair<std::string, float> >::iterator itData;
	std::ifstream inputFile;
	inputFile.open(filename.c_str());
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

		if (std::isalpha(line.c_str()[0]))
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
		std::istringstream valueStr(line.substr(line.find('|') + 1));
		if (!(valueStr >> value))
		{
			std::cerr << "Error: Invalid value => " << line.substr(line.find('|') + 1) << std::endl;
			continue;
		}
		if (valueValidity(value) == false)
		{
			std::cerr << "Error: Invalid value => " << line.substr(line.find('|') + 1) << std::endl;
			continue;
		}
	
		//itData = std::find_if(_data.begin(), _data.end(), CompareFirst(key));
		std::map<std::string, float>::iterator itData = _data.find(key);
		std::string closestDate;
		if (itData == _data.end())
		{
			closestDate = findClosestDate(key);
			//itData = std::find_if(_data.begin(), _data.end(), CompareFirst(closestDate));
			itData = _data.find(closestDate);
		}
		if (itData != _data.end())
			std::cout << key << " => " << value << " * " << itData->second << " = " << value * itData->second << std::endl;
		else
			std::cerr << "Error: Date not found" << std::endl;
	}
}	

std::string	BitcoinExchange::findClosestDate(const std::string& date)
{
	std::string closestDate;
	std::map<std::string, float>::iterator it = _data.lower_bound(date);
	// std::list<std::pair<std::string, float> >::iterator it;

    if (it == _data.begin())
    	closestDate = it->first;
	else if (it == _data.end())
	{
		--it;
		closestDate = it->first;
	}
	else
	{
		if (it->first == date)
			closestDate = it->first;
		else
		{
			--it;
			closestDate = it->first;
    	}
	}
	
	// for (it = _data.begin(); it != _data.end(); it++)
	// {
	// 	if (it->first < date)
	// 		closestDate = it->first;
	// }
	// if (closestDate == "")
	// 	closestDate = _data.begin()->first;
	return closestDate;
}

/* ************************************************************************** */