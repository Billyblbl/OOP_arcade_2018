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
	#include <memory>

//data cache template, object needs to have a constructor wich takes a
//std::string corresponding to the path of a file on the system
// TODO : find an assert thingy to enforce this without gibberish compiler
// errors
template<class object>
class Cache {
	public:
		Cache(): _database(nullptr) {}
		~Cache() = default;

	// typedef	std::pair<object, std::size_t>	counted;

	struct Counted {
		public:
		Counted(const std::string &path):
			obj(path),
			counter(0)
		{};
		~Counted() = default;

		object		obj;
		std::size_t	counter;
	};

	object	&get(const std::string &path);
	void	letGo(const std::string &path);
	void	discard(const std::string &path);

	typedef std::unordered_map<std::string, Counted >	Database;

	protected:
	private:
		std::unique_ptr<Database>	_database;
};

template<class object>
object	&Cache<object>::get(const std::string &path)
{
	if (_database.get() == nullptr)
		_database.reset(new Database);
	_database->try_emplace(path, path);
	_database->at(path).counter++;
	return _database->at(path).obj;
}

template<class object>
void	Cache<object>::letGo(const std::string &path)
{
	_database->at(path).counter--;
	if (_database->at(path).counter <= 0)
		_database->erase(path);
}

template<class object>
void	Cache<object>::discard(const std::string &path)
{
	_database->erase(path);
}

#endif /* !CACHE_HPP_ */
