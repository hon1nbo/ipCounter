## Introduction

IP addresses can be annoying to count by hand, especially for large networks with disconnected segments.
I have scripted things in the past, but decided to make a tool for it to release.

The tool was originaly written in c++ simply because the last time I wrote it I needed to make it quickly, and I could bash out 
C based programs much faster than python etc.
I have since included a Python based version. The C++ version is here for posterity purposes.

The tool works, but still needs improvement. However, it gets the basics done.


## Supported Formats

Count IPv4 addresses in multiple formats, including:

Prefix format (CIDR):
```
Y.Y.Y.Y/XX
```

Range format:
```
X.X.X.X-Y.Y.Y.Y
```

Singles:
```
X.X.X.X
```

## Limitations

The tool currently has some limitations.
- It only supports IPv4 at the moment (IPv6 coming, but given the nature of IPv6 allocations may not be as useful)
- Tool assumes no white space at the moment
- RegEx is currently not implemented to provide even greater format support

## System Requirements

None really. The Python version should work with anything after 2.5. As for the C++ version, as long as you can compile a 
standard C/C++ program (there is a macro to call windows.h IFF on windows so it is cross platform)

## Usage

ipCounter.py /path/to/ip/list

## Sample Output
The following is a sample output from the Python verison. The Windows/Linux native is similar.
```
10.0.15.2-10.1.26.4 :  134147
192.168.1.0/24 :  256
192.168.4.0/23 :  512
127.0.0.1 : 1
iterated through  4  entries
Total IPs Counted:  134916
```

## Future
- Implement IPv6 support
- implement white space handling
- implement RegEx
