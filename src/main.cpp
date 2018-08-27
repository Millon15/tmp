/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 16:37:55 by vbrazas           #+#    #+#             */
/*   Updated: 2018/08/27 10:01:21 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Parser.hpp>

int			main( int ac, const char **ap )
{
	try {
		Parser		P( ac, ap );
		P.parse();
	}
	catch( const std::exception &e ) {		std::cerr << e.what() << std::endl;	}

	return 0;
}
