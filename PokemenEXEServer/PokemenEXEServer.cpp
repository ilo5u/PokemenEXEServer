// PokemenEXEServer.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Kernel.h"

#pragma comment(lib, "WS2_32.lib")

int main(int argc, char *argv[])
{
	char szCmdLine[BUFSIZ];
	if (!InitServer())
	{
		printf("初始化服务器环境失败。\n");
		return 1;
	}

	fprintf(stdout, "键入help命令以查看帮助。\n");

	std::string szQueryResult;
	while (true)
	{
		fprintf(stdout, "> ");
		fgets(szCmdLine, BUFSIZ, stdin);
		szCmdLine[std::strlen(szCmdLine) - 1] = 0x0;
		if (std::strcmp(szCmdLine, "start server") == 0)
		{
			if (!RunServer())
			{
				printf("启动服务器失败。\n");
			}
		}
		else if (std::strcmp(szCmdLine, "close server") == 0)
		{
			// TODO
		}
		else if (std::strcmp(szCmdLine, "list users launched") == 0)
		{
			szQueryResult = QueryServer(szCmdLine);

			fprintf(stdout, szQueryResult.c_str());
			fprintf(stdout, "\n");
		}
		else if (std::strcmp(szCmdLine, "list users connected") == 0)
		{
			// TODO
		}
		else if (std::strncmp(szCmdLine, "list pokemens of ", std::strlen("list pokemens of ")) == 0)
		{
			int userid = 0;
			fscanf(stdin, "list pokemens of %d", &userid);

			// TODO
		}
	}
    return 0;
}

