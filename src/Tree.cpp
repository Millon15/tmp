/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 06:58:15 by vbrazas           #+#    #+#             */
/*   Updated: 2018/08/27 10:06:03 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Tree.hpp>

Tree				*Tree::last = nullptr;
int					Tree::id = 0;

Tree::Tree( const std::string &sT, Tree *father ) :
	startTag(sT), parent(father), cur_id(++Tree::id) {}
Tree::~Tree( void )
{
	delete &startTag;
}


void		Tree::removeChild( void )
{
	for ( std::list< Tree* >::iterator i = childrens.begin();
		i != childrens.end(); i++ )
	{
		if ( (*i)->cur_id == Tree::id )
			(*i)->close();
	}
}
Tree		*Tree::addChild( const std::string &sT )
{
	static const std::string	tags[] = {
		"<root>", "<intervals>", "<interval>", "<low>", "<hight>"
	};

	for ( int i = 0; i < 4; i++ )
		if ( sT != tags[i] )													throw std::logic_error("Bad tag");

	Tree::last = new Tree(sT, this);
	childrens.push_back( Tree::last );
	return Tree::last;
}
void		Tree::close( const std::string &closeTag )
{
	if ( closeTag.size() < 3 || childrens.size() > 0 )							throw std::logic_error("Bad tag");
	if ( closeTag.compare(2, closeTag.npos, startTag, 1, startTag.npos) != 0 )	throw std::logic_error("Bad closed tag");
	this->close();
}
void		Tree::close( void )
{
	if ( parent != nullptr )
		for ( std::list< Tree* >::iterator i = parent->childrens.begin();
			i != parent->childrens.end(); i++ )
		{
			if ( (*i)->cur_id == this->cur_id )
				parent->childrens.erase(i);
		}
}
