#include "stdafx.h"

using namespace System;
using namespace System::IO::Ports;

int main(array<System::String ^> ^args)
{

	String^ answer;
	String^ portName;
	int baudRate = 9600;
	Console::WriteLine("Type in a port name and hit ENTER");
	portName = Console::ReadLine();
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
			//Console::WriteLine("Type \"L\" \"R\" \"U\" \"D\" \"F\" or \"B\" to test the operation");
			Console::WriteLine("Type L L' R or R' to test the operation");
			// get answer
			answer = Console::ReadLine();

			/*if (String::Compare(answer, "open") == 0)
				arduino->WriteLine("0"); // send 0 to arduino
			else if (String::Compare(answer, "close") == 0)
				arduino->WriteLine("1"); // send 1 to arduino*/

			//check that user typed one of the options
			if (String::Compare(answer, "L") == 0)
				arduino->WriteLine("0"); // send 0 to arduino
			else if (String::Compare(answer, "R") == 0)
				arduino->WriteLine("2"); // send 1 to arduino
			else if (String::Compare(answer, "L'") == 0)
					arduino->WriteLine("1"); // send 0 to arduino
			else if (String::Compare(answer, "R'") == 0)
				arduino->WriteLine("3"); // send 0 to arduino
				
			/*else if (String::Compare(answer, "U") == 0)
				arduino->WriteLine("2"); // send 2 to arduino
			else if (String::Compare(answer, "D") == 0)
				arduino->WriteLine("3"); // send 3 to arduino
			else if (String::Compare(answer, "F") == 0)
				arduino->WriteLine("4"); // send 4 to arduino
			else if (String::Compare(answer, "B") == 0)
				arduino->WriteLine("5"); // send 5 to arduino */
			else
				Console::WriteLine(answer + " was not an option");
			// ask user if he wants to continue
			Console::WriteLine("Try again? yes/no");
			// get answer
			answer = Console::ReadLine();
			// clear the screen
			Console::Clear();
		} while (String::Compare(answer, "yes") == 0);
		// close port to arduino
		arduino->Close();
	}
	catch (IO::IOException^ e)
	{
		Console::WriteLine(e->GetType()->Name + ": Port is not ready");
	}
	catch (ArgumentException^ e)
	{
		Console::WriteLine(e->GetType()->Name + ": incorrect port name syntax, must start with COM/com");
	}
	// end program
	Console::Write("Press enter to close the program");
	Console::Read();
	return 0;
}
