/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 06:59:51 by vbrazas           #+#    #+#             */
/*   Updated: 2018/08/28 06:54:38 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <stdexcept>
# include <string>
# include <list>

class Tree
{
private:
	int						cur_id;

	static int				id;

	void		validateTag( const std::string &sT );

public:
	Tree( void );
	Tree( const std::string &sT, Tree *father = nullptr );
	~Tree( void );

	std::list< Tree* >		childrens;
	Tree					*parent;
	const std::string		&startTag;

	Tree		*addChild( const std::string &sT );
	Tree		*removeChild( const std::string &sT );
};

#endif
