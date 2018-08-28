/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 05:32:31 by vbrazas           #+#    #+#             */
/*   Updated: 2018/08/28 09:07:04 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

# include <stdexcept>
# include <iostream>
# include <fstream>
# include <string>
# include <cctype>
# include <cstring>
# include <vector>
# include <list>
# include <thread>
# include <utility>

# include <Tree.hpp>

using trinity		= struct s_trinity;
using filestype		= std::vector< trinity* >;
using successpair	= std::pair< bool, int >;
using successtype	= std::list< successpair* >;

struct		s_trinity
{
	s_trinity( std::ifstream *fl, const char *fln, int cr = 0 ) :
		file(fl),
		filename(fln),
		currow(cr),
		curFather(nullptr)
	{}
	~s_trinity() {}

	successtype			intervals;
	Tree				*curFather;
	std::ifstream		*file;
	const char			*filename;
	int					currow;
};

class Parser
{
private:
//									Main Parser's vectors Section
	filestype		_files;

//									Error Section
	void			putError( const filestype::iterator &i, const std::string &last );
	void			putUsage( int ac, const char **ap ) const;

//									Main Parser's functions Section
	void			parseWork( filestype::iterator i );
	void			validityCheck( trinity &t, char *token, std::string &str );

public:
	Parser( int ac, const char **ap );
	~Parser( void );

	void			compile( void );
};

#endif
