/*
	This is some code I found that takes input from the user to send to an arduino through a COM port.
	After building a string with commands for the solve solution, we can use similar methods to send them one
	at a time to the arduino. We can use ReadLine to wait for the arduino to send a signal that it finished 
	a command, then send the next.
	-- Austin Powers
	I tested, it works.
*/

#include "stdafx.h"

using namespace System;
using namespace System::IO::Ports;

int main(array<System::String ^> ^args)
{
	
	String^ answer;
	String^ portName;
	int baudRate=9600;
	Console::WriteLine("Type in a port name and hit ENTER");
	portName=Console::ReadLine();
	// arduino settings
	SerialPort^ arduino;
	arduino = gcnew SerialPort(portName, baudRate);
	// open port
	try
	{
		arduino->Open();

		do
		{
			// ask on or off
			Console::WriteLine("Type command");
			// get answer
			answer=Console::ReadLine();
			//check that user typed one of the options
			if(String::Compare(answer,"forward")==0)
				arduino->WriteLine("0"); // send 1 to arduino
			else if(String::Compare(answer,"backward")==0)
				arduino->WriteLine("1"); // send 0 to arduino
			else if (String::Compare(answer, "left") == 0)
				arduino->WriteLine("2"); // send 0 to arduino
			else if (String::Compare(answer, "right") == 0)
				arduino->WriteLine("3"); // send 0 to arduino
			else if (String::Compare(answer, "dance") == 0)
				arduino->WriteLine("4"); // send 0 to arduino
			else
				Console::WriteLine(answer+" was not an option");
			// ask user if he wants to continue
			Console::WriteLine("Try again? yes/no");
			// get answer
			answer=Console::ReadLine();
			// clear the screen
			Console::Clear();
		}while(String::Compare(answer,"yes")==0);
		// close port to arduino
		arduino->Close();
	}
	catch (IO::IOException^ e  ) 
	{ 
		Console::WriteLine(e->GetType()->Name+": Port is not ready");
	}
	catch (ArgumentException^ e)
	{
		Console::WriteLine(e->GetType()->Name+": incorrect port name syntax, must start with COM/com");
	}
	// end program
	Console::Write("Press enter to close the program");
	Console::Read();
    return 0;
}