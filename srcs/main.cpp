
#include "Irc.hpp"
#include "Server.hpp"
#include <signal.h>


bool server_help = false;

void handleSig(int sig)
{
	if (sig == SIGINT)
		server_help = true;
    for(int i = 0; i < 1020; ++i)
    {
        close(i);
    }
}

int errorMsg(std::string msg){
    std::cout << msg << std::endl;
    return 1;
}

int main(int ac, char **av)
{
    Server serverClass;
    
    signal(SIGINT, handleSig);
    if(ac != 3)
        return (errorMsg("Wrong number of arguments"));

    if(serverClass.setPort(av[1]) == -1)
        return (errorMsg("Invalid port number"));
    serverClass.savePass(av[2]);    
    serverClass.inicializeServer();
    return 0;
}
