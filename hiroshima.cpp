#include <string>
#include <iostream>
#include <cstdlib>

#undef WAR

static int	peace = 1;

class	Food
{
private:
	std::string	_type;

public:
	Food(std::string const &type): _type(type) {}
	virtual	~Food() {}
	Food(Food const &rhs): _type(rhs._type) {}

	Food	process(std::string const &type)
	{
		this->_type = this->_type + " " + type;
		return *this;
	}
	std::string const	&process() const
	{
		return this->_type;
	}
	Food	operator+(Food const &rhs) const
	{
		return Food("(" + this->_type + " " + rhs._type + " +)");
	}
};
std::ostream	&operator<<(std::ostream &ost, Food const &rhs)
{
	return ost << rhs.process();
}

int	main()
{
	Food	okonomiyaki = ((Food("小麦粉")+Food("水")).process("混ぜる")
			+(Food("野菜")+Food("肉"))+Food("麺").process("炒める")
			+Food("卵").process("伸ばす")
			).process("焼く").process("重ねる")
			+(Food("ソース")+Food("青海苔"));
	std::cout << "広島::お好み焼き = "  << okonomiyaki << std::endl;
	while (peace++)
		;
	if (!peace)
		abort();
	return (0);
}
