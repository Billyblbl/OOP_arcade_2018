/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Arcade specific definition of commonly used types
*/

#ifndef TYPES_HPP_
    #define TYPES_HPP_

	#include <string>
	#include <cstdint>

template<typename nb>
struct Vector2 {
	public:
	Vector2<nb>() = default;
	Vector2<nb>(const std::string &format);
	nb	x;
	nb	y;
};

template<typename nb>
Vector2<nb>::Vector2(const std::string &format)
{
	if (format[0] != '[' || format[format.length() - 1] != ']')
		throw std::runtime_error(std::string(__func__) + " parse error : " + format);
	std::string coord(format.substr(1, format.size() - 2));
	std::size_t	coma = coord.find(',');
	std::string	xString(coord.substr(0, coma));
	std::string	yString(coord.substr(coma + 1));
	x = std::atoi(xString.c_str());
	y = std::atoi(yString.c_str());
	if ((x == 0 && xString != "0") || (y == 0 && yString != "0"))
		throw std::runtime_error(std::string(__func__) + " parse error : " + format);
}

union Color {
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;
	uint32_t	value;
};

#endif /* !TYPES_HPP_ */
