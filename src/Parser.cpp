/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 05:32:18 by vbrazas           #+#    #+#             */
/*   Updated: 2018/08/28 11:19:14 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Parser.hpp>

Parser::Parser( int ac, const char **ap )
{
	putUsage( ac, ap );
	_files.reserve(20);
	for ( int i = 1; i < ac; i++ ) {
		try {
			_files.push_back( new trinity(new std::ifstream(ap[i]), ap[i]) );
		}
		catch( const std::exception &e ) {
			std::cerr << e.what() << std::endl;
		}
	}
}
Parser::~Parser( void ) {}


void					Parser::putUsage( int ac, const char **ap ) const
{
		 if ( ac > 2 )					return ;
	else if ( ac == 1 || !strcmp(ap[1], "--help") || !strcmp(ap[1], "-help") || !strcmp(ap[1], "?") ) {
		throw std::logic_error(
			"Usage: ./calculate_prime <xml_file>"
		);
	}
}
void					Parser::putError( const trinity &t, const std::string &errmessage )
{
	std::string			errstr( t.filename );

	errstr += ":onRow ";
	errstr += std::to_string( t.currow );
	errstr += ": ";
	errstr += errmessage;

	throw std::logic_error(errstr);
}
void					Parser::validityCheck( trinity &t, char *token, std::string &str )
{
	Tree				*parent;
	std::size_t			checker;
	std::string			tok = std::string(token);;

	if ( t.curFather == nullptr ) {
		if ( tok != "root>" ) {
			throw std::logic_error("Attempt to start document not from <root> tag");
		}
		t.curFather = new Tree( tok, nullptr );
	}
	else if ( isalpha(tok[0]) ) {
		t.curFather = t.curFather->addChild( tok );
	}
	else if ( tok[0] == '/' ) {
		if ( t.curFather->startTag != tok.substr(1) ) {
			throw std::logic_error("Bad close tag");
		}
		parent = t.curFather->parent;
		delete t.curFather;
		t.curFather = parent;
	}
	else if ( isdigit(tok[0]) ) {
		if ( t.curFather->startTag == "low>" ) {
			t.intervals.push_back( new successpair( true, std::stoi(tok.c_str(), &checker) ));
		}
		else if ( t.curFather->startTag == "high>" ) {
			t.intervals.push_back( new successpair( false, std::stoi(tok.c_str(), &checker) ));
		}
		else
			throw std::logic_error("Bag characters ocurred");
		if ( checker != tok.size() )
			throw std::logic_error("Bag characters ocurred");
	}
	else
		throw std::logic_error("Bag characters ocurred");
}
void					Parser::parseWork( filestype::iterator i )
{
	if ( !*(*i)->file )
		putError( **i, "Wrong filename" );

	std::string						str = std::string();
	char							*token;

	for (; *(*i)->file; str.clear() ) {
		std::getline( *(*i)->file, str );
		(*i)->currow++;
		
		for (token = ::strtok( const_cast<char*>(str.c_str()), "<\t\n\v\f\r " );
			token;
			token = ::strtok( NULL, "<\t\n\v\f\r " ))
		{
			try {
				validityCheck( **i, token, str );
			} catch( const std::exception &e ) { putError( **i, e.what() ); }
		}
	}
	if ( Tree::id != 0 )
		putError( **i, "Not only all tags have been closed in the document" ); // Hello Klitchko!
	checkAndTranslateIntervals( **i );
}
void					Parser::checkAndTranslateIntervals( trinity &t )
{
	int			l = 0;
	bool		flag[2] = { true, false };

	for ( successtype::iterator i = t.intervals.begin(); i != t.intervals.end(); i++, l++ ) {
		if ( !(l % 2) ) {
			if ( flag[0] + flag[1] != true ) {
				putError( t, "Error occured while parsing intervals" );
			}
			flag[0] = false;
			flag[1] = false;
			t.end.push_back( new int [2] );
		}
		flag[ l % 2 ] = (*i)->first;
		(*t.end.rbegin())[ l % 2 ] = (*i)->second;
	}
}
void					Parser::computerWork( endtype::iterator e )
{
	Computer	C( *e );

	C.computePrime();
}
void					Parser::compile( void )
{
	std::vector<std::thread>		tr;

	for ( filestype::iterator i = _files.begin(); i != _files.end(); i++ ) {
		try {
			tr.push_back( std::thread( &Parser::parseWork, std::ref(*this), i ));
		}
		catch( const std::exception &e ) { std::cerr << e.what() << std::endl; }
	}
	for ( std::vector<std::thread>::iterator i = tr.begin(); i != tr.end(); i++ ) {
		i->join();
	}
	tr.clear();

	for ( filestype::iterator i = _files.begin(); i != _files.end(); i++ ) {
		for ( endtype::iterator l = (*i)->end.begin(); l != (*i)->end.end(); l++ ) {
			try {
				tr.push_back( std::thread( &Parser::computerWork, std::ref(*this), l ));
			}
			catch( const std::exception &e ) { std::cerr << e.what() << std::endl; }
		}
	}
	for ( std::vector<std::thread>::iterator i = tr.begin(); i != tr.end(); i++ ) {
		i->join();
	}
}
