#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "Application.h"

#include <string>

#ifndef printf_console
  #define printf_console printf
#endif

class Manager {
public:
	static void RegisterApplication(Application* app);
	static Application* GetApplication();
private:
	static Application* application;
};

#endif /* define(__MANAGER_H__) */
