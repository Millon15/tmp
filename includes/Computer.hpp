/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:38:05 by vbrazas           #+#    #+#             */
/*   Updated: 2018/08/28 11:20:20 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdexcept>
# include <fstream>

class Computer
{
private:
	int			*_interval;

public:
	Computer( int *e );
	~Computer( void );

	//									Main Computer's functions Section
	void			computePrime( void );
};
