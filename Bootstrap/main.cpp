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
		return -1;
	}

	std::string str(argv[1]);

	File::SetExecDir(str.c_str());

	auto app = new Application();
	Manager::RegisterApplication(app);
	app->Init();
	return 0;
}
