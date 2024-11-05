#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(const std::string &level)
{
    std::map<std::string, void (Harl::*)()> logLevels;
        logLevels["DEBUG"] = &Harl::debug;
        logLevels["INFO"] = &Harl::info;
        logLevels["WARNING"] = &Harl::warning;
        logLevels["ERROR"] = &Harl::error;
        
    std::map<std::string, void (Harl::*)()>::iterator it = logLevels.begin();
    for (; it != logLevels.end(); ++it)
    {
        if (it->first == level)
        {
            (this->*(it->second))();
            return;
        }
    }
    std::cout << "Invalid log level" << std::endl;
}

void Harl::debug() {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning() {
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}