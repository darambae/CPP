/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:58:45 by dabae             #+#    #+#             */
/*   Updated: 2024/08/20 17:39:31 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

//Using std::stack
/*
Characteristics:
- LIFO (Last In First Out) structure.
- Elements are pushed/popped from the top.
- No iterators.
- Simplicity('push','pop','top'...) and efficiency(O(1)).
*/
class RPN
{

	public:

		RPN();
		RPN( RPN const & src );
		~RPN();

		RPN &		operator=( RPN const & rhs );
		void	run(const std::string& input);
		float	calculate(float n1, float n2, char operat);

	private:
		std::stack<float> _input;
};


#endif /* ************************************************************* RPN_H */