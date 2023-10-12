#include "main.h"
#pragma comment(lib, "user32")

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	LockGuard::main form;
	Application::Run(% form);
	return 0;
}