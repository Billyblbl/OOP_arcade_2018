/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Generic cache data collection template
*/

#ifndef CACHE_HPP_
    #define CACHE_HPP_

	#include <string>
	#include <unordered_map>

//data cache template, object needs to have a constructor wich takes a
//std::string corresponding to the path of a file on the system
// TODO : find an assert thingy to enforce this without gibberish compiler
// errors
template<class object>
class Cache {
	public:
		Cache() = default;
		~Cache() = default;

	typedef	std::pair<object, std::size_t>	counted;

	object	&get(const std::string &path);
	void	letGo(const std::string &path);

	protected:
	private:
		std::unordered_map<std::string, counted>	_database;
};

template<class object>
object	&Cache<object>::get(const std::string &path)
{
	_database.try_emplace(path, counted(path, 0));
	_database.at(path).second++;
	return _database.at(path).first;
}

template<class object>
void	Cache<object>::letGo(const std::string &path)
{
	_database.at(path).second--;
	if (_database.at(path).second <= 0)
		_database.erase(path);
}

#endif /* !CACHE_HPP_ */
