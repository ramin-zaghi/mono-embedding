#include "Manager.h"
#include "File.h"
#include <string>
#include <iostream>
#include <fstream>

static Manager manager;

int main(int argc, const char* argv[])
{
	if (argc < 2) {
		printf("Please specify where your Mono installation root can be found on the command line.\n");
		printf("You may specify --debug as your second argument to run this in debug mode over 127.0.0.1:10000.\n");
		return -1;
	}

	std::string arg1(argv[1]);
	File::SetExecDir(arg1.c_str());

	auto app = new Application();
	Manager::RegisterApplication(app);

	if (NULL != argv[2]) {
		std::string arg2(argv[2]);
		std::string debugCommand("--debug");
		if (0 == arg2.compare(debugCommand)) {
			app->EnableDebugMode();
		}
	}

	app->Init();
	return 0;
}
