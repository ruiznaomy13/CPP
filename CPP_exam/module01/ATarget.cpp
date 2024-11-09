
#include "ATarget.hpp"

ATarget::ATarget(const std::string& type)
    : _type(type) {}

ATarget::ATarget(const ATarget& other)
{
    *this = other;
}

ATarget&    ATarget::operator=(const ATarget& other)
{
    if (this == &other)
        _type = other._type;
    return (*this);
}

ATarget::~ATarget() { }

void    ATarget::getHitBySpell(ASpell& spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << std::endl;
}
