#include <iostream>

class Entity
{
private:
	float	_x, _y;
public:
	Entity();
	~Entity();
	void	Print();
};

Entity::Entity()
{
	_x = 0.0f;
	_y = 0.0f;
}

Entity::~Entity()
{
	std::cout << "Entity has been destroyed!" << std::endl;
}

void	Entity::Print()
{
	std::cout << _x << ", " << _y << std::endl;
}

void	manager()
{
	Entity	e;

	e.Print();
}

int	main(void)
{
	manager();

	std::cin.get();

}