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
        for(short byte = 24; byte >= 0; byte -= 8){
            ipS << ((ip >> byte) & 0xff) << ((byte > 0) ? "." : "");    
        }
        std::cout << ipS.str() << std::endl;
    }
}

inline void SortIP::list2()
{
    for (auto ip : v_ip4)
    {
        std::stringstream ipS1;
        short byte1;
        ipS1 << ((ip >> byte1) & 0xff);
        if ((ipS1.str() == "1")){
            std::stringstream ipS;
            for(short byte = 24; byte >= 0; byte -= 8){
                ipS << ((ip >> byte) & 0xff) << ((byte > 0) ? "." : "");
            }
            std::cout << ipS.str() << std::endl;
        }
    }
}

inline void SortIP::list3()
{
    for (auto ip : v_ip4)
    {
        bool yesornot{false};
        for (short byte2 = 24; byte2 >= 16; byte2 -= 8)
        {
            std::stringstream ipS1;
            ipS1 << ((ip >> byte2) & 0xff);
            if ((ipS1.str() != "46")&&(byte2 == 24))
            {
                byte2 = 0;
                yesornot = false;
                break;
            }
            if ((ipS1.str() != "70")&&(byte2 == 16))
            {
                byte2 = 0;
                yesornot = false;
                break;
            }
            yesornot = true;
        }
        if (yesornot == true)
        {
            std::stringstream ipS;
            for(short byte = 24; byte >= 0; byte -= 8){
                ipS << ((ip >> byte) & 0xff) << ((byte > 0) ? "." : "");    
            }
            std::cout << ipS.str() << std::endl;
        }
    }
}

inline void SortIP::list4()
{
    for (auto ip : v_ip4)
    {
        std::stringstream ipS;
        bool yesornot{false};
        for(short byte = 24; byte >= 0; byte -= 8){
            ipS << ((ip >> byte) & 0xff) << ((byte > 0) ? "." : "");
            std::stringstream ipS1;
            ipS1 << ((ip >> byte) & 0xff);
            if(ipS1.str() == "46")
            {
                yesornot = true;
            }    
        }
        if (yesornot == true)
        {
            std::cout << ipS.str() << std::endl;
        }
    }
}
