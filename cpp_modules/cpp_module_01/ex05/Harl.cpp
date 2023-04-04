#include <iostream>

#include "Harl.hpp"

void Harl::complain(std::string level) const
{
	static const size_t level_count = 4;
	static const std::string level_strs[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	const t_complain_func level_funcs[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	size_t i = 0;
	while (level.compare(level_strs[i]) && i < level_count) i++;
	if (i < level_count)
		(this->*level_funcs[i])();
}

void Harl::debug(void) const
{
	std::cout
		<< "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
		<< "I really do!"
		<< std::endl;
}

void Harl::info(void) const
{
	std::cout
		<< "I cannot believe adding extra bacon costs more money. "
		<< "You didn't put enough bacon in my burger! "
		<< "If you did, I wouldn't be asking for more!"
		<< std::endl;
}

void Harl::warning(void) const
{
	std::cout
		<< "I think I deserve to have some extra bacon for free. "
		<< "I've been coming for years whereas you started working here since last month."
		<< std::endl;
}

void Harl::error(void) const
{
	std::cout
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}
