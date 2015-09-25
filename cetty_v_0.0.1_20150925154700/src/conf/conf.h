#include <string>
#include <iostream>
#include <fstream>
#include "../type/type.h"
#include "../log/log.h"

#ifndef CETTY_CONF_
#define CETTY_CONF_


#define DEFAULT_PORT 2046

#define DEFAULT_IP 0.0.0.0

#define DEFAULT_WORKER 10

#define DEFAULT_REQQUEUE 1000

#define DEFAULT_PROPERITES "./conf/cetty.conf"

using namespace std;
class CettyConf{                        
    private :
        string cettyConf;
		SSMAP * globalReg;
    public :
        void setCettyCOnf(string c){    
            cettyConf = c;
        }
        string getCettyConf(){          
            return cettyConf;
        }
		void setGlobalReg(SSMAP* s){
			globalReg = s;
		}
		SSMAP * getGlobalReg(){
			return globalReg;
		}
		void readCettyConf(){
			//从配置文件中读取数据
			log( DEBUG, "try read cetty conf ["+cettyConf + "]");
			ifstream in;
			in.open(getCettyConf().c_str());
			if(!in){
				log( DEBUG, "conf open failed");
				exit(-1);
			}
			log( DEBUG, "conf open success");
			string temp;
			while(getline(in,temp)){
				if(temp.find('#',0)==0){
					continue;
				}
				if(temp.find('=')==string::npos){
					continue;
				}
				string key = temp.substr(0,temp.find('=',0));
				string value = temp.substr(temp.find('=',0)+1);
				log( INFO, "key["+key+"],value["+value+"]");
				(*globalReg).insert(pair<string,string>(key,value));
			}
			in.close();
			
		}
};

void readConfFile();
void showGlobalReg();
string getReg(const char *);
#endif
