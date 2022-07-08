/*
 *  RadiusClass -- An C++-Library for radius authentication 
 *					and accounting.
 * 
 *  Copyright (C) 2005 EWE TEL GmbH/Ralf Luebben <ralfluebben@gmx.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
 
#ifndef _ERROR_H_
#define _ERROR_H_

/** Error number definitions. These number are returned if
 * a error occurs. */
#define ALLOC_ERROR -1
#define SOCKET_ERROR -2
#define BIND_ERROR -3
#define NO_BUFFER_TO_UNSHAPE -4
#define UNKNOWN_HOST -5
#define POINTER_MUST_BE_NULL -6
#define BAD_LENGTH -7
#define PARSING_ERROR -8
#define BAD_FILE -9
#define TO_BIG_ATTRIBUTE_LENGTH -10
#define BAD_IP -11
#define NO_RESPONSE -12
#define TO_LONG_PASSWORD -13
#define SHAPE_ERROR -14
#define UNSHAPE_ERROR -15
#define NO_VALUE_IN_ATTRIBUTE -16
#define WRONG_AUTHENTICATOR_IN_RECV_PACKET -17
#endif //_ERROR_H_
