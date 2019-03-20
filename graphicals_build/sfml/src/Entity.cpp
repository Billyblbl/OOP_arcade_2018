/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Entity file to object class methods
*/

#include <fstream>
#include <sstream>
#include "Entity.hpp"

Entity::Entity(const std::string &path):
	_spritePath("")
{
	std::ifstream	file(path);
	if (!file.is_open())
		throw std::runtime_error(std::string(__func__) + "Can't open entity file : " + path);
	std::string		buf;
	while (std::getline(file, buf, '\n')) {
		if (buf.length() == 0 || buf[0] == '#')
			continue;
		if (_spritePath.size() == 0)
			_spritePath = buf;
		else
			_states.emplace_back(buf);
	}
}

Entity::CoordinatesI::CoordinatesI(const std::string &format)
{
	if (format[0] != '[' || format[format.size() - 1] != ']')
		throw std::runtime_error(std::string(__func__) + " parse error : " + format);
	std::size_t	coma = format.find(',');
	std::string	xString = format.substr(1, coma);
	std::string	yString = format.substr(coma + 1, format.size() - 2);
	x = std::atoi(xString.c_str());
	y = std::atoi(yString.c_str());
	if ((x == 0 && xString != "0") || (y == 0 && yString != "0"))
		throw std::runtime_error(std::string(__func__) + " parse error : " + format);
}

Entity::State::State(const std::string &format)
{
	std::stringstream			stream(format);
	std::string					buf;
	std::vector<std::string>	split;
	while(std::getline(stream, buf, ':'))
		split.emplace_back(buf);
	if (split.size() != 6)
		throw std::runtime_error(std::string(__func__) + " parse error : " + format);
	name = split[0];
	upLeft = split[1];
	downRight = split[2];
	color.value = static_cast<unsigned>(std::atoi(split[3].c_str()));
	backColor.value = static_cast<unsigned>(std::atoi(split[4].c_str()));
	ascii = split[5][0];
}

Entity::iterator	Entity::begin()
{
	return _states.begin();
}

Entity::iterator	Entity::end()
{
	return _states.end();
}

const std::string	&Entity::getSpritePath() const
{
	return _spritePath;
}