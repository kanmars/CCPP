#include "log.h"
#include "type.h"
#include "conf.h"

map_ss CettyConf::confReg;
int main(){
	Logger::info("ABCDEE");
	CettyConf::init();
}
