/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:43:04 by vbrazas           #+#    #+#             */
/*   Updated: 2018/08/28 13:34:21 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Computer.hpp>

Computer::Computer( int *e, const char *filename ) : _interval(e), _filename(filename) {}
Computer::~Computer( void ) {}


int				*Computer::initSieve( void )
{
	int			gap = _interval[0] - _interval[1];
	if ( gap <= 0 ) {
		throw std::logic_error("Bad interval");
	}
	int			*S = new int [gap];
	int			k = _interval[1];

	for( int i = 0; i <= gap ; i++, k++ ) {
		S[i] = (k == 1) ? false : k;
	}

	return S;
}
void			Computer::printCompution( int *S, int k, int n )
{
	std::ofstream	log(_filename, std::ofstream::app);

	log << "\n<root>\n\t<primes>\n\t\t";
	for( int i = 0; k <= n; i++, k++ ) {
		if ( S[i] ) {
			log << S[i] << " ";
		}
	}
	log << "\n\t<\\primes>\n<\\root>\n";
}
void			Computer::stupidAlgo( int *S, int k, int n )
{
	for ( int i = 0; k + i <= n; i++ ) {
			 if ( !((k + i) % 2)  )		S[i] = false;
		else if ( !((k + i) % 3)  )		S[i] = false;
		else if ( !((k + i) % 5)  )		S[i] = false;
		else if ( !((k + i) % 7)  )		S[i] = false;
		else if ( !((k + i) % 9)  )		S[i] = false;
		else if ( !((k + i) % 11) )		S[i] = false;
		else if ( !((k + i) % 13) )		S[i] = false;
		else if ( !((k + i) % 25) )		S[i] = false;
	}
}
void			Computer::computePrime( void )
{
	int			*S = initSieve();
	int			k = _interval[1];
	int			n = _interval[0];

	stupidAlgo( S, k, n );

	printCompution( S, k, n );
}
