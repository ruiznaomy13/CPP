#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <map>
#include <iostream>

#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
	private :
		Warlock & operator=(Warlock const & rhs);
		Warlock(Warlock const & obj);
		Warlock();
		std::string _name;
		std::string _title;
		std::map<std::string, ASpell*>	book;
		
	public :
		Warlock(const std::string& name, const std::string& title);
		~Warlock();

		std::string const & getName() const;
		std::string const & getTitle() const;

		void	setTitle(std::string const & str);
		void	introduce() const;
		void	learnSpell(ASpell* spell);
		void	forgetSpell(std::string spellName);
		void	launchSpell(std::string spellName, const ATarget& target);
};

#endif 
