// g++ serial.c++ -lboost_system -lws2_32 -D _WIN32_WINNT=0x0501

#include <stdlib.h>
#include <string>
#include <conio.h>
#include <iostream>
#include "SimpleSerial.hpp"

#define BAUD 9600

using namespace std;
using namespace boost;



/*int main(int argc, char* argv[])
{

	string inputstr;
	cout << "Lab 5 Code Started" << endl;

	/*When you are dealing with IO devices, it is vaery important that calls to them be wrapped in 'try-catch' blocks.
	These blocks of code thell the program 'if something goes wrong (an exception) run whatever is in catch rather 
	than simply killing the program.
	*/
	/*while (inputstr != "EXIT"){
		try { 

			// Make a SimpleSerial object with the parameter for your Wunderboard/OS
			SimpleSerial wunder("COM3", BAUD);

			// Start reading data from your wunderboard and displaying it to the screen.
			cout << wunder.readLine() << endl;
			// Check if there is input to be read from the keyboard
			// If there is THEN read it, otherwise ignore the keyboard
			// If you just readt data at it is 'EXIT' retunr from the program
			if(_kbhit()){
				cin >> inputstr;
			
			
			}
		} catch(boost::system::system_error& e)
		{
			cout<<"Error: "<<e.what()<<endl;
			return 1;
		}
	}
}*/