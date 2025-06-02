#pragma once
#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <algorithm>


class SortIP
{
private:
    std::vector <uint32_t> v_ip4;

    bool compare(uint32_t a, uint32_t b)
    {
        return a > b;
    }


public:

    SortIP(const char* filepath);
    //~SortIP();
    void list1(); //fullsort
    void list2(); //first == 1
    void list3(); //first=46, second=70
    void list4(); //any 46
};
inline SortIP::SortIP(const char* filepath)
{
    std::ifstream file_r;
    file_r.open(filepath, std::ifstream::in);
    if (!file_r.is_open()) 
		{	
			std::cout << "Ошибка открытия файла!" << std::endl;
		}
    std::string ipv4;
    while (std::getline(file_r, ipv4))
    {
        try
        {
            auto onlyip = ipv4.substr(0, ipv4.find("\t", 0));
            auto ip = onlyip.c_str();
            v_ip4.push_back(inet_network(ip));
        }
        catch (...)
        {
            continue;
        }
    }

    std::sort(v_ip4.begin(), v_ip4.end(), [this] (uint32_t a, uint32_t b) {return compare(a,b);});
}

inline void SortIP::list1()
{
    for (auto ip : v_ip4)
    {
        std::stringstream ipS;
        for(short byte = 24; byte >= 0; byte -= 8)
        {
            ipS << ((ip >> byte) & 0xff) << ((byte > 0) ? "." : "");
        }
        std::cout << ipS.str() << std::endl;
    }
}

inline void SortIP::list2()
{
    for (auto ip : v_ip4)
    {
        std::stringstream ipS;
        uint8_t t;
        bool needprint{false};
        for(short byte = 24; byte >= 0; byte -= 8)
        {
            ipS << ((ip >> byte) & 0xff) << ((byte > 0) ? "." : "");
            t = (ip >> byte) & 0xff;
            if ((t == 1)&&(byte == 24))
            {
                needprint = true;
            }   
        }
        if (needprint == true)
        {
            std::cout << ipS.str() << std::endl;
        }
    }
}

inline void SortIP::list3()
{
    for (auto ip : v_ip4)
    {
        std::stringstream ipS;
        uint8_t t;
        bool needprint1{false};
        bool needprint2{false};
        for(short byte = 24; byte >= 0; byte -= 8)
        {
            ipS << ((ip >> byte) & 0xff) << ((byte > 0) ? "." : "");
            t = (ip >> byte) & 0xff;
            if ((t == 46)&&(byte == 24))
            {
                needprint1 = true;
            }
            if ((t == 70)&&(byte == 16))
            {
                needprint2 = true;
            }   
        }
        if ((needprint1 == true)&&(needprint2 == true))
        {
            std::cout << ipS.str() << std::endl;
        }
    }
}

inline void SortIP::list4()
{
    for (auto ip : v_ip4)
    {
        std::stringstream ipS;
        uint8_t t;
        bool needprint{false};
        for(short byte = 24; byte >= 0; byte -= 8)
        {
            ipS << ((ip >> byte) & 0xff) << ((byte > 0) ? "." : "");
            t = (ip >> byte) & 0xff;
            if (t == 46)
            {
                needprint = true;
            }   
        }
        if (needprint == true)
        {
            std::cout << ipS.str() << std::endl;
        }
    }
}
