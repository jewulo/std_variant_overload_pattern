#pragma once

#include <iostream>
#include <string>
#include <variant>


namespace using_variant
{
	void run()
	{
		std::variant<int, float> v, w;

		std::cout << '\n';

		v = 12;
		int i = std::get<int>(v);
		std::cout << i << '\n';

		w = std::get<int>(v);
		i = std::get<int>(w);
		std::cout << i << '\n';

		w = std::get<0>(v);
		std::cout << std::get<int>(w) << '\n';

		//std::get<double>(v);	// ERROR
		//std::get<3>(w);		// ERROR

		try {
			float f = std::get<float>(w);
		}
		catch (std::bad_variant_access&) {}

		std::variant<std::string> x("abc");
		x = "def";

		std::cout << '\n';
	}
}

