/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 06:59:51 by vbrazas           #+#    #+#             */
/*   Updated: 2018/08/27 10:05:50 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <stdexcept>
# include <string>
# include <list>

struct Tree
{
public:
	Tree( const std::string &sT, Tree *father = nullptr );
	~Tree( void );

	std::list< Tree* >		childrens;
	Tree					*parent;
	const std::string		&startTag;
	int						cur_id;
	static Tree				*last;
	static int				id;

	Tree		*addChild( const std::string &sT );
	void		removeChild( void );
	void		close( const std::string &closeTag );

private:
	void		close( void );
};

#endif
