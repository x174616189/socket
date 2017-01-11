#include "Socket_Until.h"

ssize_t SUntil::readn(int fd, char *str, size_t n) {
	size_t nleft;
	ssize_t nread;
	const char *p = str;

	nleft = n;
	while(nleft > 0) {
		if( (nread = read(fd, p, nleft)) < 0) {
			if(errno == EINTR) {
				nread = 0;
			}
			else {
				return -1;
			}
		}
		else if(nread == 0) {
			break;
		}

		nleft -= nread;
		p += nread;
	}
	return n-nleft;
}

ssize_t SUntil::writen(int fd, char *str, size_t n) {
	size_t nleft;
	ssize_t nwritten;
	const char *p = str;

	nleft = n;
	while(nleft > 0) {
		if( (nwritten = write(fd, p, nleft)) <= 0) {
			if(nwritten < 0 && errno == EINTR) {
				nwritten = 0;
			}
			else {
				return -1;
			}
		}

		nleft -= nwritten;
		p += nwritten;
	}
	return n;
}


