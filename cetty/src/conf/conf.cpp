#include <iostream>
#include "../reg/reg.h"
using namespace std;
SSMAP globalReg;

void readConfFile(){
	CettyConf cettyConf;
	cettyConf.setCettyCOnf(DEFAULT_PROPERITES);
	cettyConf.setGlobalReg(&globalReg);
	cettyConf.readCettyConf();
}
void showGlobalReg(){
	log(INFO,"SHOW globalReg INFO BEGIN");
	SSMAP::iterator ite;
	for(ite=globalReg.begin();ite!=globalReg.end();ite++){
		log(INFO,((string)ite->first)+" = "+((string)ite->second));
	}
	log(INFO,"SHOW globalReg INFO END");

}
string getReg(const char * regName){
	string s(regName);
	return globalReg[s];
}

