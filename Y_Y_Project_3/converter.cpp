#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
 

int convert(bool parH, bool parR, bool parN, bool parQ, char paramCSVFileName[], char paramHTMLFileName[], char paramBG[][50], char paramFG[][50])
{
	std::ifstream MyFile(paramCSVFileName);
	
	if (!MyFile)
	{
		printf("Error opening CSV file.");
		return 1;
	}

	std::ofstream OutputFile(paramHTMLFileName);

	if (!OutputFile)
	{
		printf("Error opening HTML file.");
		return 1;
	}

	OutputFile << "<DOCTYPE! html>" << std::endl;

	OutputFile << "<html>" << std::endl;

	OutputFile << "<head>" << std::endl;

	OutputFile << "<title>" << std::endl;

	OutputFile << paramCSVFileName << std::endl;

	OutputFile << "</title>" << std::endl;

	if (true)
	{
		OutputFile << "<style>" << std::endl;

		for (size_t i = 0; i < 50; i++)
		{
			if (paramBG[i][0] == '\0')
			{
				break;
			}

			if (i==0)
			{
				OutputFile << "th { background-color: ";
			}
			else
			{
				OutputFile << ".tr";
				OutputFile << i;
				OutputFile << " { background-color: ";
			}
			OutputFile << paramBG[i];
			OutputFile << "; color: ";
			OutputFile << paramFG[i];
			OutputFile << ";}" << std::endl;
		}


		OutputFile << "</style>" << std::endl;
		
	}

	OutputFile << "</head>" << std::endl;
	OutputFile << "<body>" << std::endl;
	OutputFile << "<table cellspacing='0' cellpadding='0'>" << std::endl;

	int index = 0;
	std::string line;
	while (std::getline(MyFile, line))
	{
		//printf("%s", line);

		std::vector<std::string> tokens;
		std::istringstream iss(line);
		std::string token;

		while (std::getline(iss, token, ',')) {
			tokens.push_back(token);
		}

		OutputFile << "<tr>" << std::endl;
		for (const std::string& t : tokens) {
			if (index == 0)
			{
				OutputFile << "<th>" << std::endl;
				OutputFile << t << std::endl;
				OutputFile << "</th>" << std::endl;
			}
			else
			{
				OutputFile << "<td>" << std::endl;
				OutputFile << t << std::endl;
				OutputFile << "</td>" << std::endl;

			}
		}
		OutputFile << "</tr>" << std::endl;

		index++;
	}

	OutputFile << "</table>" << std::endl;
	OutputFile << "</body>" << std::endl;
	OutputFile << "</html>" << std::endl;
	
	MyFile.close();

	return 0; 

}