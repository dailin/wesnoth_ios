/* $Id: stub.hpp 52007 2011-11-18 00:55:10Z anonymissimus $ */
/*
   By Ignacio R. Morelle <shadowm2006@gmail.com>
   Part of the Battle for Wesnoth Project http://www.wesnoth.org/

   This source code file is not copyrighted.
*/

#ifndef STUB_HPP_INCLUDED
#define STUB_HPP_INCLUDED

#include <boost/current_function.hpp>
#define STUB() \
	std::cerr << "Ouch[stub]: " << BOOST_CURRENT_FUNCTION << " [at " << __FILE__ << ":" << __LINE__ << "]\n"

#endif
