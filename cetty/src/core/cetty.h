#include <../reg/reg.h>
#include <../cnf/conf.h>

class Conf{
	private:
		string conf;
	public :
		void setConf( string c ){
			conf = c;
		}
		void getConf(){
			return conf;
		}
};

void readConfFile(){
	Conf c = new Conf();
	c.setConf("aa");
	cout<< c.getConf() << endl;
}
