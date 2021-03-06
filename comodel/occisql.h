/* -------------------------------------------------------------------- */
/*  ACCORDS PLATFORM                                                    */
/*  (C) 2011 by Iain James Marshall (Prologue) <ijm667@hotmail.com>     */
/* -------------------------------------------------------------------- */
/* Licensed under the Apache License, Version 2.0 (the "License"); 	*/
/* you may not use this file except in compliance with the License. 	*/
/* You may obtain a copy of the License at 				*/
/*  									*/
/*  http://www.apache.org/licenses/LICENSE-2.0 				*/
/*  									*/
/* Unless required by applicable law or agreed to in writing, software 	*/
/* distributed under the License is distributed on an "AS IS" BASIS, 	*/
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 	*/
/* implied. 								*/
/* See the License for the specific language governing permissions and 	*/
/* limitations under the License. 					*/
/* -------------------------------------------------------------------- */

#ifndef	_occi_sql_h
#define	_occi_sql_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	OCCI_MYSQL 

#ifndef	public
#define	public
#endif

#ifndef	private
#define	private	static
#endif

#ifdef	OCCI_MYSQL
#include <mysql/mysql.h>
#endif

#define	_CREATE_DATABASE	"CREATE DATABASE IF NOT EXISTS "
#define	_CREATE_TABLE		"CREATE TABLE IF NOT EXISTS "
#define	_DEFAULT_HOST		"127.0.0.1"
#define	_DEFAULT_USER		"admin"
#define	_DEFAULT_PASS		"admin"
#define	_DEFAULT_BASE		"database"

struct	occi_table
{
	struct	occi_table * previous;
	struct	occi_table * next;
	char * 	name;
	char *	description;
	char *	base;
	char *	host;
	int	status;
	int	port;
	char *	user;
	char * 	pass;
	MYSQL *	handle;
};

struct	occi_expression
{
	char *	value;
	int	(*handler)(char *, char *, int);
};

public	void *	allocate(int);
public	void *	liberate(void *);
public	char *	allocate_string(char *);

public	int	initialise_occi_sql( char * databasename, char * username, char * password );
public	void	terminate_occi_sql();
public	int	initialise_occi_sql_table( char * tablename, char * description );
public	int	drop_occi_sql_table( char * tablename );
public	int	first_occi_sql_record( char * category, struct occi_expression *expression );
public	int	previous_occi_sql_record( char * category, struct occi_expression *expression );
public	int	insert_occi_sql_record( char * category, struct occi_expression *expression );
public	int	search_occi_sql_record( char * category, struct occi_expression *expression );
public	int	update_occi_sql_record( char * category, struct occi_expression *expression );
public	int	delete_occi_sql_record( char * category, struct occi_expression *expression );
public	int	next_occi_sql_record( char * category, struct occi_expression *expression );
public	int	last_occi_sql_record( char * category, struct occi_expression *expression );

	/* ----------- */
#endif	/* _occi_sql_h */
	/* ----------- */


