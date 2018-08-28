/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:38:05 by vbrazas           #+#    #+#             */
/*   Updated: 2018/08/28 12:08:34 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdexcept>
# include <fstream>

class Computer
{
private:
	int				*_interval;

	int				*initSieve( void );
	void			printCompution( int *S );

public:
	Computer( int *e );
	~Computer( void );

	//									Main Computer's functions Section
	void			computePrime( void );
};
