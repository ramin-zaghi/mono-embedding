#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <mono/jit/jit.h>
#include <thread>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#ifndef printf_console
  #define printf_console printf
#endif

class Application
{
public:
	void Init();
	void InitializeMono();
	void Run();
	bool StartMonoAndLoadAssemblies();
	void StopMono();
	bool StartMono();
	void FireOnReload();

private:
	std::string assemblyDir;
	MonoDomain* domain;
	std::vector<MonoImage*> images;
	std::vector<MonoObject*> instances;
};

#endif /* define(__APPLICATION_H__) */
