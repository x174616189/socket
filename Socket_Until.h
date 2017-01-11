#include <sys/socket.h>
//#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <map>
#include <string>
#include <set>
#include <sstream>
#include <map>

using namespace std;

class SUntil {
public:
	static ssize_t readn(int fd, char *str, size_t n);
	static ssize_t writen(int fd, char *str, size_t n);

};
