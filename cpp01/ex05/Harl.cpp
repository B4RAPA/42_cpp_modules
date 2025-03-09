
#include "Harl.hpp"


Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
	return ;
}
/*
Harl::FunctionMapping function_mappings[] = {
    {"debug", &Harl::debug},
    {"info", &Harl::info},
    {"warning", &Harl::warning},
    {"error", &Harl::error}
};

void	Harl::complain( std::string level )
{
	for (int i = 0; i < 4; i++)
	{
		if (function_mappings[i].level == level)
		{
			HarlMemFn func = function_mappings[i].function;
			(this->*func)();
			return;
		}
	}
}*/

void Harl::complain(std::string level)
{
	const std::string levels[4] = {"debug", "info", "warning", "error"};
	HarlFunct funct[4]  = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*funct[i])();
			return ;
		}
	}
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special" <<
				 " ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put" <<
				  "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
			  << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for" <<
				  "years, whereas you started working here just last month."
			  << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
