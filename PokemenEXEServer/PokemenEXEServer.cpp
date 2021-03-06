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
	fprintf(stdout, "> ");
	while (true)
	{
		fgets(szCmdLine, BUFSIZ, stdin);
		szCmdLine[std::strlen(szCmdLine) - 1] = 0x0;
		if (std::strcmp(szCmdLine, "s") == 0)
		{
			if (!RunServer())
			{
				printf("启动服务器失败。\n");
			}
			fprintf(stdout, "\n> ");
		}
		else if (std::strcmp(szCmdLine, "c") == 0)
		{
			// TODO
			fprintf(stdout, "\n> ");
		}
		else if (std::strcmp(szCmdLine, "li") == 0)
		{
			fprintf(stdout, "\n> ");
		}
		else if (std::strcmp(szCmdLine, "lc") == 0)
		{
			szQueryResult = QueryServer(szCmdLine);

			fprintf(stdout, szQueryResult.c_str());
			fprintf(stdout, "\n> ");
		}
		else if (std::strncmp(szCmdLine, "lp", std::strlen("lp")) == 0)
		{
			int userid = 0;
			fscanf(stdin, "lp %d", &userid);
			fprintf(stdout, "\n> ");
			// TODO
		}
	}
    return 0;
}

