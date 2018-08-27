/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 05:32:31 by vbrazas           #+#    #+#             */
/*   Updated: 2018/08/27 09:59:37 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

# include <stdexcept>
# include <iostream>
# include <fstream>
# include <string>
# include <cctype> // for isspace()
# include <cstring> // for strcmp()
# include <vector>
# include <thread>
# include <utility> // for pair

# include <Tree.hpp>

# define NEWLINE_CHAR		('\n')

struct		s_trinity
{
	s_trinity() : thread(nullptr), file(nullptr), filename(nullptr), currow(0), curcolumn(0) {}
	s_trinity( std::thread *trd, std::ifstream *fl, const char *fln, int cr = 0, int cc = 0 ) :
		thread(trd), file(fl), filename(fln), currow(cr), curcolumn(cc) {}
	~s_trinity() {}
	std::thread			*thread;
	std::ifstream		*file;
	const char			*filename;
	int					currow;
	int					curcolumn;
	bool				is_parent;
};

class Parser
{
using trinity		= struct s_trinity;
using filestype		= std::vector< trinity* >;
using successtype	= std::vector< std::pair< bool, int >* >;

private:
//									Main Parser's vectors Section
	filestype		_files;
	Tree			*_parserTree;
	Tree			*_curFather;
	successtype		_intervals;

//									Error Section
	void			putError( const filestype::iterator &i, const std::string &last );
	void			putUsage( int ac, const char **ap ) const;

//									Main Parser's functions Section
	void			parseWork( filestype::iterator &i );
	void			getValue( const filestype::iterator &i, const std::string &last );
	void			getTag( const filestype::iterator &i, const std::string &last );
	bool			findAndCompareTag( const filestype::iterator &i, const std::string &last );

public:
	Parser( void );
	Parser( int ac, const char **ap );
	~Parser( void );

	void			parse( void );
};

#endif
