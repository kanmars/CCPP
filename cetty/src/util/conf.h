#include "log.h"
#include "type.h"

#ifndef CETTY_CONF_
#define CETTY_CONF_

#define CETTY_DEFAULT_CONF_FILE  "conf/cetty.conf"

class CettyConf{
	public:
		static map_ss confReg;	
	public:
		static void init(){
			ifstream in(CETTY_DEFAULT_CONF_FILE);
			if(!in){
				Logger::error("Open DefaultFile[CETTY_DEFAULT_CONF_FILE] fail");
				exit(-1);
			}
			string temp;
			while(getline(in,temp)){
				if(temp.find('#',0)==0){
					continue;
				}
				if(temp.find('=',0)==string::npos){
					continue;
				}
				string key = temp.substr(0,temp.find('=',0));
				string value = temp.substr(temp.find('=',0)+1);
				Logger::info("LOAD CONF: key["+key+"]  value["+value+"]");
				confReg.insert(pair<string,string>(key,value));
			}
			in.close();
		}
		static string getConf(string confname){
			if(confReg.count(confname)>0){
				return confReg[confname];
			}
			return "";
		}
		
		
};
#endif
