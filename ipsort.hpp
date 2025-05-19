#pragma once
#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>

class SortIP
{
private:
    std::vector <uint32_t> v_ip4;
    
public:

    SortIP(const char* filepath);
    ~SortIP();
};
inline SortIP::SortIP(const char* filepath)
{
    std::ifstream file_r;
    file_r.open(filepath, std::ifstream::in);
}