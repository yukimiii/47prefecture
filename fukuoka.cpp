#include <string>
#include <iostream>
#include <map>
#include <thread>
#include <chrono>

int	main()
{
	std::map<std::string, time_t>	m = {
		{"raw", 1}, {"wire", 10}, {"very-hard", 20}, {"hard", 30}, {"hard-ish", 40}, {"normal", 60}, {"soft-ish", 90}, {"soft", 120},
		{"nama", 1}, {"harigane", 10}, {"bari", 20}, {"kata", 30}, {"katame", 40}, {"futsuu", 60}, {"yawame", 90}, {"yawa", 120},
	};
	std::cout << "how soft would you like?\n> ";
	time_t		t;
	std::cin >> t;
	if (!std::cin)
	{
		std::cin.clear();
		std::string	str;
		std::cin >> str;
		if (!m.count(str))
		{
			std::cout << "sorry, I don't know that..." << std::endl;
			return 1;
		}
		t = m[str];
	}

	std::cout << "boiling";
	for (int i = 1; i <= t; ++i)
	{
		std::cout << (i%10 ? "." : ":") << std::flush;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	std::cout << " here you go!" << std::endl;
	return 0;
}
