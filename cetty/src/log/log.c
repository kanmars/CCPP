#include "../log/log.h"
#include <sys/time.h>

void log( LEVEL l,string s){
	struct timeval now;
	gettimeofday(&now, NULL);
	//正常写法是time_t t = time(NULL);
	time_t t = (time_t)(now.tv_sec);
	struct tm *local = localtime(&t);
	char tmbuff[20];
	strftime(tmbuff,20,"%Y%m%d%H%M%S,",local);
	long tickl = now.tv_usec/1000;
	tmbuff[19]='\0';
	tmbuff[18]='0'+tickl%10;
	tmbuff[17]='0'+tickl/10%10;
	tmbuff[16]='0'+tickl/100%10;
	tmbuff[15]=' ';
	
	if( l == INFO ){
		cout << "INFO ["<< tmbuff <<"] " << s << endl;
	}else if( l == DEBUG ){
		cout << "DEBUG["<< tmbuff <<"] " << s << endl;
	}else if( l == ERROR ){
		cout << "ERROR["<< tmbuff <<"] " << s << endl;
	}
}
