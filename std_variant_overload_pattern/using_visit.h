#pragma once

#include <iostream>
#include <typeinfo>
#include <vector>
#include <variant>

namespace using_visit
{
	void run()
	{
		std::cout << '\n';

		std::vector<std::variant<char, long, float, int, double, long long>>
			vec_variant = { 5,'2',5.4,100ll,2011l,3.5f,2017 };

		for (auto& v : vec_variant) {
			std::visit([](auto arg) {std::cout << arg << " "; }, v);
		}

		std::cout << '\n';

		for (auto& v : vec_variant) {
			std::visit([](auto arg) {std::cout << typeid(arg).name() << " "; }, v);
		}

		std::cout << '\n';
	}
}

