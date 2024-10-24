/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:50:02 by dabae             #+#    #+#             */
/*   Updated: 2024/08/19 11:26:49 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <algorithm>
# include <stdexcept>
# include <sstream>
# include <cmath>

/*std::map*/
/*
Characteristics:
- An associative container (fast search, insertion, deletion).
- Elements are sorted by key.
- Unique keys.

Note: it sorts the keys automatically. */

class BitcoinExchange
{

	public:

		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();

		BitcoinExchange &		operator=( BitcoinExchange const & rhs );
		
		void		dataToList();
		void 		printResult(const std::string& filename);
		std::string	findClosestDate(const std::string& date);
		
		private:
			std::map<std::string, float> _data;
};


#endif /* ************************************************* BITCOINEXCHANGE_H */