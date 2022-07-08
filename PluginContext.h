/*
 *  radiusplugin -- An OpenVPN plugin for do radius authentication 
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
 
#ifndef _CONTEXT_H_
#define _CONTEXT_H_
#include "UserPlugin.h"
#include "RadiusClass/RadiusConfig.h"
#include "UserPlugin.h"
#include "IpcSocket.h"
#include "Config.h"
#include <sys/types.h>
#include <list>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


using std::map;
using std::list;


using namespace std;


/** This class saves all information for the different processes and 
 * it saves the users for the foreground process.*/
class PluginContext
{
private:
	  	
  	pid_t authpid; 					/**< Process ID of authentication background process. */
  	
  	pid_t acctpid; 					/**< Process ID of accounting background process. */

  	int verb; 						/**< Verbosity level of OpenVPN. */
  
  	map<string, UserPlugin *> users; 	/**< The user list of the plugin in for the foreground process which are authenticated.*/
  	list< UserPlugin *> newusers; 	        /**< The user list of the plugin in for the foreground process which are waiting for authentication.*/
  	list< UserPlugin *> newacctusers; 	/**< The user list of the plugin in for the foreground process which are waiting for accounting.*/
	
        list <int> nasportlist; 		/**< The port list. Every user gets an unipue port on connect. The number is deleted if the user disconnects, a new user can
									get the number again. This is important for dynamic IP address assignment via the radius server.*/
	
	int sessionid; 					/**< Every user gets a new session id. The session is never decremented.*/ 

        pthread_cond_t condsend;
        pthread_mutex_t mutexsend;
        pthread_cond_t condrecv;
        pthread_mutex_t mutexrecv;
        pthread_t thread; 
        pthread_cond_t acctcondsend;
        pthread_mutex_t acctmutexsend;
        pthread_cond_t acctcondrecv;
        pthread_mutex_t acctmutexrecv;
        pthread_t acctthread; 
        bool stopthread;
        bool startthread;
        int result;

        pthread_mutex_t usermutex;

	
public:
  	
  	IpcSocket 	authsocketforegr; 	/**< Object from the class IpcSocket, it saves the socket to the foregroundprocess from the authentication background process.*/
  	IpcSocket	authsocketbackgr; 	/**< Object from the class IpcSocket, it saves the socket to the authentication background process.*/ 
  	IpcSocket	acctsocketforegr; 	/**< Object from the class IpcSocket, it saves the socket to the accounting background process.*/	
  	IpcSocket	acctsocketbackgr; 	/**< Object from the class IpcSocket, it saves the socket to the accounting background process-*/	
  	
  	RadiusConfig radiusconf; 		/**< The object saves the radius configuration from the config file.*/
  	Config		conf;				/**< The object saves the configuration from the config file.*/
  				
	PluginContext(void);
	~PluginContext(void);
	
	int addNasPort(void);
	void delNasPort(int );
	
	UserPlugin * findUser(string);
	void addUser(UserPlugin *);
	void delUser(string );
	
  	
  	int getVerbosity(void);
  	void setVerbosity(int);
  		
  	
  	pid_t getAuthPid(void); 				
  	void setAuthPid(pid_t); 
  	
  	pid_t getAcctPid(void); 				
  	void setAcctPid(pid_t); 
  	
  	int getSessionId(void);
  	
  	pthread_cond_t * getCondSend(void);
        //void setCond(pthread_cond_t);
        pthread_cond_t * getCondRecv(void);
      
        pthread_mutex_t * getMutexSend(void);
        pthread_mutex_t * getMutexRecv(void);
        //void setMutex(pthread_mutex_t);

        pthread_cond_t * getAcctCondSend(void);
        //void setCond(pthread_cond_t);
        pthread_cond_t * getAcctCondRecv(void);
      
        pthread_mutex_t * getAcctMutexSend(void);
        pthread_mutex_t * getAcctMutexRecv(void);
        //void setMutex(pthread_mutex_t);
        
        UserPlugin * getNewUser();
        UserPlugin * getNewAcctUser();
        void addNewUser(UserPlugin * newuser);
        void addNewAcctUser(UserPlugin * newuser);

        pthread_t * getThread();
        pthread_t * getAcctThread();
        
        int getResult();
        void setResult(int);

        bool getStopThread();
        void setStopThread(bool);

        bool UserWaitingtoAuth();
        bool UserWaitingtoAcct();

        bool getStartThread();
        void setStartThread(bool);

   
        
  	
	
};

#endif //_CONTEXT_H_
