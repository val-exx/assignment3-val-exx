#include <stdio.h>
#include <syslog.h>

int main(int argc, char *argv[]) {

	//open log with log_user facility
	openlog(NULL,0,LOG_USER);

	if(argc!=3){
		//syslog with log_error priority
		syslog(LOG_ERR, "Invalid number of arguments.");
		return 1;
	}

	char *filepath=argv[1];
	char *str=argv[2];

	FILE *file = fopen(argv[1], "w");
	if (file!=NULL) {
		fputs(str,file);
		
		//syslog with log_debug priority
		syslog(LOG_DEBUG, "Writing <%s> string to file <%s>.", str,filepath);

		fclose(file);
	}
	else {
		syslog(LOG_ERR, "File <%s> not created.",filepath);
	}
	return 0;
}
