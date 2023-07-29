#pragma once

#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <variant>

namespace using_overload
{
	//  The overload pattern
	template <typename ... Ts>
	struct Overload : Ts ... {
		using Ts::operator()...;
	};
	// Class template argument deduction (CTAD) guide for Overload<>
	template <class... Ts> Overload(Ts...) -> Overload<Ts...>;

	void run()
	{
		std::cout << '\n';

		std::vector<std::variant<char, long, float, int, double, long long>>
			vec_variant = { 5,'2',5.4,100ll,2011l,3.5f,2017 };

		auto TypeOfIntegral = Overload {
			[](char) {return "char"; },
			[](int) {return "int"; },
			[](unsigned int) {return "unsigned int"; },
			[](long int) {return "long int"; },
			[](long long int) {return "long long int"; },
			[](auto) {return "unknown type"; }
		};

		for (auto v : vec_variant) {
			std::cout << std::visit(TypeOfIntegral, v) << '\n';
		}

		std::cout << '\n';

		std::vector<std::variant<std::vector<int>, double, std::string>>
			vec_variant2 = { 1.5, std::vector <int>{1,2,3,4,5}, "Hello" };

		auto DisplayMe = Overload {
			[](std::vector<int>& my_vec) { 
				for (auto v : my_vec)
					std::cout << v << " ";
				std::cout << '\n';
			},
			[](auto& arg) { std::cout << arg << '\n'; },
		};
		for (auto v : vec_variant2) {
			std::visit(DisplayMe, v);
		}

		std::cout << '\n';
	}
}

