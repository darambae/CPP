/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:42:12 by dabae             #+#    #+#             */
/*   Updated: 2024/08/13 14:58:03 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

class Span
{

	public:

		Span();
		Span(unsigned int N);
		Span(Span const &src);
		~Span();

		Span &				operator=( Span const & rhs );
		void				addNumber(int n);
		int					shortestSpan(void);
		int					longestSpan(void);
		void 				fillNumber(void);
		unsigned int		getN(void) const;
		std::vector<int>	*getContainer(void) const;
		
	private:
		unsigned int _n;
		std::vector<int> *_container;

};

std::ostream &			operator<<( std::ostream & o, Span const & span );

#endif /* ************************************************************ SPAN_H */