#!/bin/python
#/**************************************************************************
#* File: ipCounter.py
#* 
#* This is a basic program to count the total number of IPs
#* in a given range. Input is a txt formatted file similar 
#* to the sample provided
#* 
#* This updated version uses Python to make it more agnostic.
#* Author: Hon1nbo
#***************************************************************************/

import math
import sys

fileName = sys.argv[1]

ipCount = 0
ipList = ""

# Open the file & read contents in
with open(fileName) as ipListFile:
	ipList = ipListFile.read()

tmpTuple = ('not','\n','null')
tmpTupleSmall = ('not',' ','null')
tmpCIDR = 0

tmpTuple = ipList.split("\n")
entriesCount = len(tmpTuple)

x = 0

while (entriesCount - x) != 0:
	tmpTupleSmall = tmpTuple[x].partition("/")
	if tmpTupleSmall[2] != "":
		tmpCount = math.pow(2, (32-int(tmpTupleSmall[2])))
		print(tmpTuple[x],": ",int(tmpCount))
		ipCount += tmpCount

	else:
		tmpTupleSmall = tmpTuple[x].partition("-");
		if tmpTupleSmall[1] == "-":

			startIP = tmpTupleSmall[0].split(".") # start IP
			endIP = tmpTupleSmall[2].split(".") # end IP
			tmpCount = 0
			for octet in range (0,4):

				# Compare each octet one by one based on iteration
				difference = int(endIP[octet]) - int(startIP[octet])

				# account for the inclusion of smaller number
				# ex) 192.168.1.0-192.168.1.255				
				if difference != 0:
					difference += 1

				# 256 addresses in each octet, raise to power to do maths
				tmpCount += (difference * pow(256, (3 - octet)))
				
			print(tmpTuple[x],": ",int(tmpCount))
			ipCount += tmpCount

		else:
			print(tmpTuple[x],": 1")
			ipCount += 1
	
	x += 1


print('iterated through ',int(x),' entries')
print('Total IPs Counted: ',int(ipCount))
