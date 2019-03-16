#ifndef READ_HPP
#define READ_HPP

#include <iostream>
#include <string>

template <typename Item>
Item read( const std::string &msg, const std::string &err, bool valid(Item))
{
    Item n;
    bool hiba;
    do{
        std::cout << msg;
        std::cin >> n;
        if((hiba=std::cin.fail())) std::cin.clear();
        std::string tmp="";
        getline(std::cin, tmp);
        hiba = hiba || tmp.size()!=0 || !valid(n);
        if(hiba) std::cout << err << std::endl;
    }while(hiba);
    return n;
}

#endif // READ_HPP
