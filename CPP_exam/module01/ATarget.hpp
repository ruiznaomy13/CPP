#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <iostream>

#include "ASpell.hpp"

class	ASpell;

class ATarget
{
	protected:
		std::string	_type;

	public:
		ATarget(const std::string& type);
		ATarget(const ATarget& other);
		ATarget& operator = (const ATarget& other);
		virtual	~ATarget();

		virtual ATarget* clone() const = 0;
		void	getHitBySpell(ASpell& spell) const;
};

#endif
