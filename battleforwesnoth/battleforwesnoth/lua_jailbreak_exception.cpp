/* $Id: lua_jailbreak_exception.cpp 48550 2011-02-19 14:17:52Z mordante $ */
/*
   Copyright (C) 2011 by Mark de Wever <koraq@xs4all.nl>
   Part of the Battle for Wesnoth Project http://www.wesnoth.org/

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/

#include "lua_jailbreak_exception.hpp"

#include <cassert>
#include <cstring> // Needed for NULL.

tlua_jailbreak_exception *tlua_jailbreak_exception::jailbreak_exception = NULL;

void tlua_jailbreak_exception::store() const throw()
{
	/*
	 * It should not be  possible to call this function with an exception still
	 * pending. It could happen if the code doesn't call
	 * tlua_jailbreak_exception::rethrow() or a logic error in the code.
	 */
	assert(!jailbreak_exception);

	jailbreak_exception = this->clone();
}

void tlua_jailbreak_exception::rethrow()
{
	if(!jailbreak_exception) {
		return;
	}

	/*
	 * We need to call tlua_jailbreak_exception::clear() after the exception
	 * is thrown. The most straightforward approach would be a small helper
	 * class calling clear in its destructor, but alas g++ then compains about
	 * an unused variable. Since we're sure there will be something thrown use
	 * that fact to make sure the the function is called.
	 */
	try {
		jailbreak_exception->execute();
	} catch(...) {
		clear();
		throw;
	}

	/* We never should reach this point. */
	assert(false);
}

void tlua_jailbreak_exception::clear() throw()
{
	delete jailbreak_exception;
	jailbreak_exception = NULL;
}
