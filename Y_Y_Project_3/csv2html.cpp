#include <stdio.h>
#include <string>
#include <cstring>
#include "helpPrinter.h"
#include "converter.h"

// defining main with arguments
int main(int argc, char* argv[])
{
	bool param_H = false;
	bool param_R = false;
	bool param_N = false;
	bool param_Q = false;
	bool param_CSVInitialized = false;
	char param_CSVFileName[100];
	bool param_HTMLInitialized = false;
	char param_HTMLFileName[100];

	bool param_bgInitialized = false;
	char param_bg[50][50];
	int param_bgIndex = 0;

	bool param_fgInitialized = false;
	char param_fg[50][50];
	int param_fgIndex = 0;

	for (size_t i = 0; i < 50; i++)
	{
		param_bg[i][0] = '\0';
		param_fg[i][0] = '\0';
	}

	for (int i = 1; i < argc; i++) {

		if (strcmp(argv[i], "--help") == 0)
		{
			printHelp();
			return 0;
		}

		if (argv[i][0] == '-' && strcmp(argv[i],"-bg")!=0 && strcmp(argv[i],"-background")!=0 && strcmp(argv[i], "-fg") != 0 && strcmp(argv[i], "-foreground") != 0)
		{
			size_t paramSize = strlen(argv[i]);
			for (int p = 1;p < paramSize;p++) {
				char param = argv[i][p];
				if (param == 'h')
				{
					param_H = true;
				}
				else if (param == 'r')
				{
					param_R = true;
				}
				else if (param == 'n')
				{
					param_N = true;
				}
				else if (param == 'q')
				{
					param_Q = true;
				}
				else
				{
					printf("Invalid parameters,[-hrnq] is expected.");
					return 0;
				}
			}
			continue;
		}

		if (param_CSVInitialized == false)
		{
			param_CSVInitialized = true;
			strcpy_s(param_CSVFileName, argv[i]);
			continue;
		}

		if (param_HTMLInitialized == false)
		{
			param_HTMLInitialized = true;
			strcpy_s(param_HTMLFileName, argv[i]);
			continue;
		}

		if (strcmp(argv[i], "-bg") == 0)
		{
			param_bgInitialized = true;
			continue;
		}

		if (strcmp(argv[i], "-background") == 0)
		{
			param_bgInitialized = true;
			continue;
		}

		if (strcmp(argv[i], "-fg") == 0)
		{
			param_bgInitialized = false;
			param_fgInitialized = true;
			continue;
		}

		if (strcmp(argv[i], "-foreground") == 0)
		{
			param_bgInitialized = false;
			param_fgInitialized = true;
			continue;
		}

		if (param_bgInitialized == true) 
		{
			strcpy_s(param_bg[param_bgIndex], argv[i]);
			param_bgIndex++;
			continue;
		}


		if (param_fgInitialized == true)
		{
			strcpy_s(param_fg[param_fgIndex], argv[i]);
			param_fgIndex++;
			continue;
		}
	}

	if (param_CSVInitialized==false)
	{
		printf("CSV filename is required\r\n");
		return 0;
	}
	if (param_HTMLInitialized == false)
	{
		strcpy_s(param_HTMLFileName, param_CSVFileName);
	}

	printf("param_H: '%d'\r\n",param_H);
	printf("param_R: '%d'\r\n", param_R);
	printf("param_N: '%d'\r\n", param_N);
	printf("param_Q: '%d'\r\n", param_Q);
	printf("CVS FileName: '%s'\r\n", param_CSVFileName);
	printf("HTML FileName: '%s'\r\n", param_HTMLFileName);

	for (int i = 0;i < 50;i++)
	{
		if (param_bg[i][0] == '\0')
		{
			break;
		}
		printf("Background param %d is: '%s'\r\n", i, param_bg[i]);
	}

	for (int i = 0;i < 50;i++)
	{
		if (param_fg[i][0] == '\0')
		{
			break;
		}
		printf("Foreground param %d is: '%s'\r\n", i, param_fg[i]);
	}

	return convert(param_H, param_R, param_N, param_Q, param_CSVFileName, param_HTMLFileName, param_bg, param_fg);
}



