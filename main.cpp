#include "ipsort.hpp"

int main()
{
    const char* filepath = "../ip_filter.tsv";    
    SortIP c_ipsort{filepath};
    //std::cout << "FULL LIST BEGIN####################" << std::endl;
    c_ipsort.list1();
    //std::cout << "FULL LIST END####################" << std::endl;

    //std::cout << "ONLY 1 BEGIN####################" << std::endl;
    c_ipsort.list2();
    //std::cout << "ONLY 1 END####################" << std::endl;

    //std::cout << "46 and 70 BEGIN####################" << std::endl;
    c_ipsort.list3();
    //std::cout << "46 and 70 END####################" << std::endl;

    //std::cout << "Any 46 BEGIN####################" << std::endl;
    c_ipsort.list4();
    //std::cout << "Any 46 END####################" << std::endl;
}