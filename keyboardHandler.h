#ifndef keyboardHandler_h
#define keyboardHandler_h

#include <vector>
#include <bits/stdc++.h>

class keyboardHandler
{
	std::unordered_map<char, bool> held;
	public:
		keyboardHandler();
		void keyDown(unsigned char key);
		void keyUp(unsigned char key);
		bool getHold(unsigned char key);
		
};
#endif