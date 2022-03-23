#include "Memory.h"



#define ENDKEY VK_DELETE
#define PAUSE std::cin.get()

int main()
{
	Attach();

	while (!GetAsyncKeyState(ENDKEY))
	{
		// Main Game Loop Here

		
		//Write<int>(Base + 0x123456, 100); // Writing value 100 to the current adress off the game
	}
	CloseHandle(hProcess);
}