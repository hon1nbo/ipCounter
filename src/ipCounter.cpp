/**************************************************************************
* File: ipCounter.cpp
* 
* This is a basic program to count the total number of IPs
* in a given range. Input is a txt formatted file similar 
* to the sample provided
* 
* Author: Jim Hartnett
***************************************************************************/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cmath>
#include "string.h"

#ifdef _WIN32
        #include "windows.h"
#endif

using namespace std;

unsigned long int countIPs(char*);
unsigned long int parseLine(string);

int main(int argc, char* argv[])
{
    char* filePath = argv[1];

    cout << "File Path: " << filePath << endl;

    unsigned long int ipCount = countIPs(filePath);
    
	cout << "Total IPs: " << ipCount << endl;

    return 0;
}


/********************************************************************** 
* countIPs takes the file path to the IP list, txt formatted,
* and returns the total number of IPs as an integer.
* This should probably be changed to a better type
**********************************************************************/

unsigned long int countIPs(char* filePath) {

	unsigned long int numberIPs = 0;

    ifstream ipList;
    ipList.open(filePath);
	string inbuf = "";

    if (!ipList.is_open() )
    {
            cerr << "Error opening IP list file!" << endl;
    }
      else
      {
        getline(ipList, inbuf);    // have one before the while loop to prime it to fix eof problems
        
        while (!ipList.eof())
        {
		  unsigned long int tempNumberIPs = parseLine(inbuf);
          numberIPs += tempNumberIPs;
		  cout << inbuf << ":  " << tempNumberIPs << endl;
          getline(ipList, inbuf);
        }

        ipList.close();
      }

	  return numberIPs;
}


/********************************************************************** 
* parseLine takes an input, a line from the file as a sting,
* and outputs the integer of the number of IPs on that line
**********************************************************************/

unsigned long int parseLine(string line) {
	
	unsigned long int numberIPs = 0;
	
	
	// first check if IP format uses a prefix
	int spot = line.find('/');
	if (spot >= 0) {
		string prefix = line.substr((spot + 1));
		int prefixInt = atoi(prefix.c_str());
		numberIPs = pow(2, (32-prefixInt));
		return numberIPs;
	}	
	else {
		// if not prefix, check if manual range
		
		int spot2 = line.find('-');
		if (spot2 >= 0) {
			string ip1 = line.substr(0,spot2);
			string ip2 = line.substr((spot2 + 1));
			
			for (int i=0; i<4;i++) {
				string temp1 = ip1.substr(0,ip1.find('.'));
				string temp2 = ip2.substr(0,ip2.find('.'));
				int number1 = atoi(temp1.c_str());
				int number2 = atoi(temp2.c_str());
				int difference = (number2 - number1);
				
				// account for the inclusion of 0
				// ex) 192.168.1.0-192.168.1.255
				if (difference != 0)
					if (number1 == 0)
						difference++;
					
				// 256 addresses in each octet, raise to power to do maths
				unsigned long int tempCount = (difference * pow(256, (3 - i)));
				numberIPs += tempCount;
		
				ip1 = ip1.substr((ip1.find('.') + 1));
				ip2 = ip2.substr((ip2.find('.') + 1));
			}
			
			return numberIPs;
		}
		else {
			// if not IP range or prefix, then single or no IP
			if (line != "") {
				return 1;
			}
			else {
				return 0;	
			}
		}
	}
}