/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:39:44 by dabae             #+#    #+#             */
/*   Updated: 2024/07/19 17:09:23 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    int index = 0;
    
    if (argc != 4)
    {
        std::cout << "ERROR (Usage: ./sed [filename] [string1] [string2])" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::string new_filename = filename + ".replace";
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string line;

    std::ifstream file(filename);
    std::ofstream new_file(new_filename);
    if (!file.is_open() || !new_file.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        return 1;
    }
    while (std::getline(file, line))
    {
        index = line.find(s1);
        while (index != -1)
        {
            line.insert(index, s2);
            line.erase(index + s2.length(), s1.length());
            index = line.find(s1, index + s2.length());
        }
        new_file << line << std::endl;
    }
    
    file.close();
    new_file.close();
    return 0;
}