/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:38:05 by vbrazas           #+#    #+#             */
/*   Updated: 2018/08/28 13:33:40 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdexcept>
# include <fstream>

class Computer
{
private:
	int				*_interval;
	const char		*_filename;

	int				*initSieve( void );
	void			printCompution( int *S, int k, int n );
	void			stupidAlgo( int *S, int k, int n );

public:
	Computer( int *e, const char *filename );
	~Computer( void );

	//									Main Computer's functions Section
	void			computePrime( void );
};
