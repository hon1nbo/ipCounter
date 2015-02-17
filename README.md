/***************************************************************************************************************
** IP Counter
** Author: Jim Hartnett
** Tool for counting the number of IPs in a given input.
** Developed for quick assessment of sizes of networks in scope for testing and QA
** takes a flat text file as input, with multiple range formats
** Current Status: Working (needs improvement)
	Basic functionality is stable for real use, but feature set is currently limited such as formatting support
****************************************************************************************************************/

# Reading Tip: this readme is laid out for syntax highlighters
# I use notepad++ with C++ highlighting enabled.

/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
 #Table of Contents:           *
                               *
 * Info                        *
 * Supported Functions         *
 * Limitations                 *
 * System Requirements         *
 * Usage                       *
 * TODOs                       *
/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\


**************
#### Info ####
**************

IP addresses can be annoying to count by hand, especially for large networks with disconnected segments.
I have scripted things in the past, but decided to make a tool for it to release.

The tool was written in c++ simply because the last time I wrote it I needed to make it quickly,
and I could bash out C based programs much faster than python etc.
I will eventually rewrite this to C only, but I made use of the c++ string search functions in a hurry.

The tool works, but still needs improvement. However, since it gets the basic job done I decided to start release.


*****************************
#### Supported Functions ####
*****************************

Count IPv4 addresses in multiple formats, including:

Prefix format:
*.*.*.*/XX
range format:
*.*.*.*-*.*.*.*
singles:
*.*.*.*

*********************
#### Limitations ####
*********************

The tool currently has some limitations.
- It only supports IPv4 at the moment (IPv6 coming, but given the nature of IPv6 allocations may not be as useful)
- Tool assumes no white space at the moment (you shouldn't really have extra white space in your range formats anyway for machine input)
- RegEx is currently not implemented (it was a quick and easy program, and there were issues with the GCC RegEx library last time I used it, so it's currently TODO)

*****************************
#### System Requirements ####
*****************************

None really, as long as you can compile a standard C/C++ program (there is a macro to call windows.h if on windows)

***************
#### Usage ####
***************

ipCounter /path/to/ip/list

***************
#### TODOs ####
***************

- implement IPv6 support
- implement white space support
- implement RegEx
- possibly rewrite in Python, but the program works and that is what matters. (though interpreted would be nice, but this was a quickie)
