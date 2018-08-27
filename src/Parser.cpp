/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 05:32:18 by vbrazas           #+#    #+#             */
/*   Updated: 2018/08/27 10:09:54 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Parser.hpp>

Parser::Parser( void ) {}
Parser::Parser( int ac, const char **ap ) : _parserTree(nullptr)
{
	putUsage( ac, ap );
	_intervals.reserve(100);
	_files.reserve(100);
	for ( int i = 1; i < ac; i++ ) {
		try {
			_files.push_back( new trinity(nullptr, new std::ifstream(ap[i]), ap[i]) );
		}
		catch( const std::exception &e ) {
			std::cerr << e.what() << std::endl;
		}
	}
}
Parser::~Parser( void )
{
	for ( filestype::iterator i = _files.begin(); i != _files.end(); i++ ) {
		(*i)->thread->join();
	}
}


void					Parser::putUsage( int ac, const char **ap ) const
{
		 if ( ac > 2 )					return ;
	else if ( ac == 1 || !strcmp(ap[1], "--help") || !strcmp(ap[1], "-help") || !strcmp(ap[1], "?") ) {
		throw std::logic_error(
			"Usage: ./calculate_prime <xml_file>"
		);
	}
}
void					Parser::putError( const filestype::iterator &i, const std::string &errmessage )
{
	std::string			errstr( (*i)->filename );

	errstr += ":";
	errstr += std::to_string( (*i)->currow );
	errstr += ":";
	errstr += std::to_string( (*i)->curcolumn );
	errstr += ": ";
	errstr += errmessage;

	throw std::logic_error(errstr);
}
void					Parser::getTag( const filestype::iterator &i, const std::string &last )
{
	// if ( last[1] == '/' ) {
	// 	if ( _parserTree == nullptr )										putError( i, "No open tag found" );
	// 	else {
	// 		try {
	// 			_parserTree.removeChild();
	// 		}
	// 		catch( const std::exception& e ) {								putError( i, e.what() ); }
	// }
	// else if ( last[1] != '/' ) {
	// 	if ( _parserTree == nullptr ) {
	// 		if ( last != "root" )											putError( i, "No <root> tag in the start of the file" );
	// 		_parserTree = new Tree("<root>");
	// 	}
	// 	else {
	// 		try { _curTree = _parserTree.addChild(last); }
	// 		catch( const std::exception& e ) {								putError( i, e.what() ); }
	// 	}
	// }
}
void					Parser::getValue( const filestype::iterator &i, const std::string &last )
{
	// std::string::size_type		sz;
	// const int					val = std::stoi(last, &sz);
	// const std::string			&toCompare = (Tree::last == nullptr) ? std::string() : Tree::last->startTag;

	// if ( last.compare(sz, last.npos, "") != 0 )								putError( i, "Bag characters ocurred" );

	// if ( toCompare == "<low>" ) {
	// 	_intervals.push_back( new std::pair< bool, int >(false, val) );
	// }
	// else if ( toCompare == "<high>" ) {
	// 	_intervals.push_back( new std::pair< bool, int >(true, val) );
	// }
	// else																	putError( i, "Bag characters ocurred" );
}
void					Parser::parseWork( filestype::iterator &i )
{
	// if ( !(*i)->file )															putError( i, "Wrong filename" );
	// std::string						*last;
	// char							c;

	// while ( (*i)->file ) {
	// 	last = new std::string();
	// 	// (*i)->file >> std::ws;
	// 	while ( (c = (*i)->file->get()) && isspace(c) ) {
	// 		if ( c == NEWLINE_CHAR ) {
	// 			(*i)->currow++;
	// 			(*i)->curcolumn = 0;
	// 		}
	// 	}
	// 	*(*i)->file >> *last;
	// 		 if ( last->empty() )											return ;
	// 	else if ( (*last)[0] != '<' )							getValue( i, *last );
	// 	else if ( last->size() > 2 && (*last)[0] == '<' )		getTag( i, *last );
	// 	else																putError( i, "Bag characters ocurred" );
	// 	(*i)->curcolumn += last->size();
	// }
}
void					Parser::parse( void )
{
	for ( filestype::iterator i = _files.begin(); i != _files.end(); i++ ) {
		try {
			(*i)->thread = new std::thread( &Parser::parseWork, std::ref(*this), std::ref(i) );
		}
		catch( const std::exception &e ) {
			std::cerr << e.what() << std::endl;
		}
	}
}
