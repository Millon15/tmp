/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 06:58:15 by vbrazas           #+#    #+#             */
/*   Updated: 2018/08/28 06:59:46 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Tree.hpp>

int					Tree::id = 0;

Tree::Tree( const std::string &sT, Tree *father ) :
	startTag(sT),
	parent(father),
	cur_id(++Tree::id)
{
	validateTag( sT );
}
Tree::~Tree( void )
{
	--Tree::id;
}

# include <fstream>

void		Tree::validateTag( const std::string &sT )
{
	static const std::string	tags[] = {
		"root>", "intervals>", "interval>", "low>", "high>"
	};
	int		i, j;

	for ( i = 0, j = 0; i < 5; i++ )
		if ( sT != tags[i] )
			j++;
	if ( i == j )
		throw std::logic_error("Not valid tag");
}
Tree		*Tree::removeChild( const std::string &sT )
{
	validateTag( sT.substr(1) );
	for ( std::list< Tree* >::iterator i = childrens.begin();
		i != childrens.end();
		i++ )
	{
		if ( Tree::id == (*i)->cur_id ) {
			childrens.erase(i);
			return (*i);
		}
	}
	if ( Tree::id == this->cur_id && childrens.empty() ) {
		return this;
	}
	throw std::logic_error("Attempt to close tag, that never've been opened");
}
Tree		*Tree::addChild( const std::string &sT )
{
	validateTag( sT );
	Tree *newChild = new Tree(sT, this);
	childrens.push_back( newChild );
	return newChild;
}
