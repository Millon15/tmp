/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:43:04 by vbrazas           #+#    #+#             */
/*   Updated: 2018/08/28 11:29:40 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Computer.hpp>

Computer::Computer( int *e ) : _interval(e) {}
Computer::~Computer( void ) {}


void					Computer::computePrime( void )
{
	// bool		*S = new [getGap(*i)] bool;

	// std::fostream	log("log", std::fostream::out);

	// // S[1] = 0; // 1 - не простое число
	// // заполняем решето единицами
	// for( k = 2; k <= n; k++ )
	// 	S[k] = true;
	
	// for(k=2; k*k<=n; k++){
	// 	// если k - простое (не вычеркнуто)
	// 	if(S[k]==1){ 
	// 		// то вычеркнем кратные k
	// 		for(l=k*k; l<=n; l+=k){
	// 			S[l]=0;
	// 			}
	// 		}
	// 	}
}
