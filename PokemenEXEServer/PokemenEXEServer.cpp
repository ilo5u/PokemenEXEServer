// PokemenEXEServer.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Kernel.h"


int main(int argc, char *argv[])
{
	if (!InitSQL())
	{
		printf("Failed to initialize the database.\n");
	}

	if (!InitServer())
	{
		printf("Failed to initialize the server.\n");
	}

	if (!RunServer())
	{
		printf("Failed to start the server.\n");
	}

	char szCmdLine[BUFSIZ];
	std::string szQueryResult;
	while (true)
	{
		printf("> ");
		fgets(szCmdLine, BUFSIZ, stdin);

		szQueryResult = QueryServer(szCmdLine);

		fprintf(stdout, szQueryResult.c_str());
	}
    return 0;
}

