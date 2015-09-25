#include "../core/cetty.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <strings.h>

using namespace std;
int main(){
	log(INFO , "Cetty Server RUN START");
	//READ ConfFile
	readConfFile();
	//init socket
	int sockfd;
	if((sockfd = socket(AF_INET,SOCK_STREAM,0))==-1){
		log(ERROR, "Socketfd open failed");
		exit(-1);
	}
	struct sockaddr_in server;
	struct sockaddr_in client;
	socklen_t len;
	len = sizeof(client);
	
	int opt = SO_REUSEADDR;
	//setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

	server.sin_family = AF_INET;
	server.sin_port = htons(atoi(getReg("DEFAULT_PORT").c_str()));
	server.sin_addr.s_addr = inet_addr(getReg("DEFAULT_IP").c_str());
	
	if(bind(sockfd,(struct sockaddr *) & server,sizeof(server)) == -1 ){
		log(ERROR, "Socketfd bind"
			+ getReg("DEFAULT_IP") + ":" + getReg("DEFAULT_PORT")
			+" failed");
		perror("listen() error.");
		exit(-1);
	}
	if(listen(sockfd,atoi(getReg("DEFAULT_REQQUEUE").c_str())) == -1){
		log(ERROR, "Socketfd listen"
			+ getReg("DEFAULT_IP") + ":" + getReg("DEFAULT_PORT") 
			+" failed");
		exit(-1);
	}
	int ep_id = epoll_create(atoi(getReg("DEFAULT_REQQUEUE").c_str()));
	struct epoll_event ev;
	ev.data.fd=sockfd;
	ev.events = EPOLLIN;
	
	epoll_ctl(ep_id,EPOLL_CTL_ADD,sockfd,&ev);

	struct epoll_event evs[atoi(getReg("DEFAULT_REQQUEUE").c_str())];
	int conn_id;	
	while(true){
		int num = epoll_wait(ep_id,evs,atoi(getReg("DEFAULT_REQQUEUE").c_str()),-1);
		int i;
		for(i=0;i<num;i++){
			if(evs[i].data.fd == sockfd){
				if(
					(conn_id
						=accept(
							sockfd,
							(struct sockaddr *) &client,
							&len
						)
					)
					==-1
				){
					log(ERROR, "accept error");
					exit(-1);	
				}
				ev.data.fd = conn_id;
				ev.events = EPOLLIN;
				epoll_ctl(ep_id, EPOLL_CTL_ADD,conn_id,&ev);
			}else{
				char recv_buff[1024];
				int recv_id;
				bzero(recv_buff,1024);
				if((recv_id = recv(conn_id , recv_buff,1024,0))==-1){
					log(ERROR, "recv error");
					exit(-1);
				}
				cout << recv_buff << endl;
			}
		}
	}
	close(sockfd);
	return 0;
}
