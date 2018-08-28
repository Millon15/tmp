/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 06:59:51 by vbrazas           #+#    #+#             */
/*   Updated: 2018/08/28 09:42:13 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <stdexcept>
# include <string>
# include <list>

struct Tree
{
	Tree( const std::string &sT, Tree *father = nullptr );
	~Tree( void );

	static int				id;

	std::list< Tree* >		childrens;
	int						cur_id;
	Tree					*parent;
	const std::string		startTag;

	void		validateTag( const std::string &sT );
	Tree		*addChild( const std::string &sT );
};

#endif
