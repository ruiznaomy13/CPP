#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>

class Warlock
{
	private:
		std::string	_name;
		std::string	_title;

	public:
		Warlock(const std::string& name, const std::string& title);
		~Warlock();

		void	setTitle(const std::string& title);
		const std::string&	getName( void ) const;
		const std::string&	getTitle( void ) const;
		void	introduce( void ) const;

	private:
		Warlock();
		Warlock(const Warlock& other);
		Warlock& operator = (const Warlock& other);
};

#endif