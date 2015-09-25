#include <iostream>
#include <fstream>
#include <string>
#include <sys/time.h>
#include <time.h>

#ifndef CETTY_LOG_H_
#define CETTY_LOG_H_

using namespace std;
class Logger {
	public:
		static void debug(string s){
			cout <<"[DEB]" << "["<<getDate()<<"] " << s << endl;
		}
		static void info(string s){
			cout <<"[INF]" << "["<<getDate()<<"] " << s << endl;
		}
		static void error(string s){
			cout <<"[ERR]" << "["<<getDate()<<"] " << s << endl;
		}
	private:
		static string getDate(){
			time_t t = (time_t)time(NULL);
			struct tm *local = localtime(&t);
			char tmpbuff[20];
			strftime(tmpbuff,20,"%Y%m%d%H%M%S,",local);
			
			struct timeval now;
			gettimeofday(&now,NULL);
			long tick_ = now.tv_usec/1000;
			tmpbuff[19]='\0';
			tmpbuff[18]='0'+tick_%10;
			tmpbuff[17]='0'+tick_/10%10;
			tmpbuff[16]='0'+tick_/100%10;
			tmpbuff[15]=' ';
			return tmpbuff;	
		}
};

#endif
