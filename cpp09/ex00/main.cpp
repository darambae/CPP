/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:52:51 by dabae             #+#    #+#             */
/*   Updated: 2024/08/19 15:57:41 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

int main(int argc, const char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc [filename]" << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    btc.printResult(argv[1]);
    return 0;
}