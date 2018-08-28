/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:43:04 by vbrazas           #+#    #+#             */
/*   Updated: 2018/08/28 12:10:07 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Computer.hpp>

Computer::Computer( int *e ) : _interval(e) {}
Computer::~Computer( void ) {}


int				*Computer::initSieve( void )
{
	int			gap = _interval[0] - _interval[1];
	if ( gap <= 0 ) {
		throw std::logic_error("Bad interval");
	}
	int			*S = new int [gap];
	int			k = _interval[0];

	for( int i = 0; i <= gap ; i++, k++ )
		S[i] = (k == 1) ? false : k;

	return S;
}
void			Computer::printCompution( int *S )
{
	int				k = _interval[0];
	int				n = _interval[1];
	std::fstream	log("log", std::fstream::out);

	log << "\n<root>\n\t<primes>\n\t\t";
	for( int i = 0; k <= n; i++, k++ ) {
		// if ( S[i] ) {
			log << S[i] << " ";
		// }
	}
	log << "\n\t<\\primes>\n<\\root>\n";
}
void			Computer::computePrime( void )
{
	int			*S = initSieve();
	int			k = _interval[0];
	int			n = _interval[1];

	
	for( int i = 0; k * k <= n; i++, k++ ) {
		// если k - простое (не вычеркнуто)
		if( S[i] ) { 
			// то вычеркнем кратные k
			for( int l = i * i; l <= n; l += i ) {
				S[l] = false;
			}
		}
	}

	printCompution( S );
}
