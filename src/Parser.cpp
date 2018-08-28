/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 05:32:18 by vbrazas           #+#    #+#             */
/*   Updated: 2018/08/28 08:13:33 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Parser.hpp>

Parser::Parser( void ) {}
Parser::Parser( int ac, const char **ap )
{
	putUsage( ac, ap );
	for ( int i = 1; i < ac; i++ ) {
		try {
			_files.push_back( new trinity(new std::ifstream(ap[i]), ap[i]) );
		}
		catch( const std::exception &e ) {
			std::cerr << e.what() << std::endl;
		}
	}
}
Parser::~Parser( void )
{

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

	errstr += ":onRow ";
	errstr += std::to_string( (*i)->currow );
	errstr += ": ";
	errstr += errmessage;

	throw std::logic_error(errstr);
}
void					Parser::validityCheck( trinity &t, char *token, std::string &str )
{
	Tree				*parent;
	std::string			tok = std::string(token);;

	if ( t.curFather == nullptr ) {
		if ( tok != "root>" ) {
			throw std::logic_error("Attempt to start document not from <root> tag");
		}
		t.curFather = new Tree( tok, nullptr );
	}
	else if ( isalpha(token[0]) ) {
		t.curFather = t.curFather->addChild( tok );
	}
	else if ( token[0] == '/' ) {
		if ( t.curFather->startTag != tok.substr(1) ) {
			throw std::logic_error("Bad close tag");
		}
		parent = t.curFather->parent;
		delete t.curFather;
		t.curFather = parent;
	}
}
void					Parser::parseWork( filestype::iterator i )
{
	if ( !*(*i)->file )
		putError( i, "Wrong filename" );

	std::string						str = std::string();
	char							*token;

	std::ofstream log("log", std::ofstream::out);

	for (; *(*i)->file; str.clear() ) {
		// str = std::string();
		std::getline( *(*i)->file, str );
		(*i)->currow++;
		
		for (token = ::strtok( const_cast<char*>(str.c_str()), "<\t\n\v\f\r " );
			token;
			token = ::strtok( NULL, "<\t\n\v\f\r " ))
		{
			try {
				validityCheck( **i, token, str );
			} catch( const std::exception &e ) { putError( i, e.what() ); }
			// else if ( isdigit(token[0]) )
			// 		(*i)->parserTree->removeChild( token );
			// else
				// putError( i, "Bag characters ocurred" );
		}
	}
	if ( Tree::id != 0 )
		putError( i, "Not only all tags have been closed in the document" ); // Hello Klitchko!
	log <<"!!! "<< Tree::id << std::endl;
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
}
