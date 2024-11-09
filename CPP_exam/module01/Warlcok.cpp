
#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock()
{
}

Warlock & Warlock::operator=(Warlock const & rhs)
{
	this->_name = rhs._name;
	this->_title = rhs._title;
	return (*this);
}

Warlock::Warlock(Warlock const & obj)
{
	*this = obj;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

std::string const & Warlock::getName() const
{
	return (_name);
}

std::string const & Warlock::getTitle() const
{
	return (_title);
}

void	Warlock::setTitle(std::string const & str)
{
	_title = str;
}

void	Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell* spell)
{
	if (spell)
		book.insert(std::make_pair(spell->getName(), spell->clone()));
}

void	Warlock::forgetSpell(std::string spellName)
{
	if (book.find(spellName) != book.end())
	{
		delete book[spellName];
		book.erase(book.find(spellName));
	}
}

void	Warlock::launchSpell(std::string spellName, const ATarget& target)
{
	if (book.find(spellName) != book.end())
		book[spellName]->launch(target);
}
