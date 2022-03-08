#include <random>
#include <exception>
#include <iostream>

class Bird: public std::runtime_error
{
public:
	Bird(const char *msg = "caught the bird!"): std::runtime_error(msg) {}
};

class BirdUncaughtException: public std::runtime_error
{
public:
	BirdUncaughtException(const char *msg = "failed to catch the bird..."): std::runtime_error(msg) {}
};

int	main()
{
	std::random_device rnd;
	try
	{
		if (rnd() % 3 == 0)
			throw Bird();
		else
			throw BirdUncaughtException();
	}
	catch (const Bird &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
