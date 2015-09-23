#include <iostream>
#include "../reg/reg.h"

SSMAP globalReg;

void readConfFile(){
	CettyConf cettyConf;
	cettyConf.setCettyCOnf("a.txt");
	cettyConf.setGlobalReg(&globalReg);
	cettyConf.readCettyConf();
	cout << 1 << endl;
	showGlobalReg();
}
void showGlobalReg(){
	log(INFO,"显示globalReg配置信息开始");
	SSMAP::iterator ite;
	for(ite=globalReg.begin();ite!=globalReg.end();ite++){
		log(INFO,((string)ite->first)+" = "+((string)ite->second));
	}
	log(INFO,"显示globalReg配置信息完毕");
}

