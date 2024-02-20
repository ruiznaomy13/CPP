#include <iostream>

class Player
{
	private:
		int	x, y;
		int	speed = 1;

	public:
		void	*move(int, int);
		Player(/* args */);
		~Player();
};

void	*Player::move(int xa, int ya)
{
	x += xa * speed;
	y += ya * speed;
}

Player::Player(/* args */)
{
}

Player::~Player()
{
}

int	main()
{
	Player	p1;
	p1.move(2, 1);

}