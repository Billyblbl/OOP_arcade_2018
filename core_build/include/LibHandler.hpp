/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** LibHandler template class
*/

#ifndef LIBHANDLER_HPP_
    #define LIBHANDLER_HPP_

	#include <string>
	#include <dlfcn.h>

template<class C>
class LibHandler {
	public:
		LibHandler(const std::string &path);
		~LibHandler();

		void	reset(const std::string &path);

		operator C &();
		operator C &() const;

		C		*operator->();
		const C	*operator->() const;

	protected:
	private:

		void	open(const std::string &path);
		void	close();

		void	*_lib;
		C		*_object;
};

template<class C>
LibHandler<C>::LibHandler(const std::string &path)
{
	open(path);
}

template<class C>
LibHandler<C>::~LibHandler()
{
	close();
}

template<class C>
void	LibHandler<C>::open(const std::string &path)
{
	_lib = dlopen(path.c_str(), RTLD_NOW);
	if (!_lib)
		throw std::runtime_error(std::string(__func__) + " : " + dlerror());
	_object = static_cast<C *>(dlsym(_lib, "LibObject"));
	if (!_object)
		throw std::runtime_error(std::string(__func__) + " : " + dlerror());
}

template<class C>
void	LibHandler<C>::close()
{
	if (dlclose(_lib))
		throw std::runtime_error(std::string(__func__) + " : " + dlerror());
}

template<class C>
void	LibHandler<C>::reset(const std::string &path)
{
	close();
	open(path);
}

template<class C>
LibHandler<C>::operator C &()
{
	return *_object;
}

template<class C>
LibHandler<C>::operator C &() const
{
	return *_object;
}

template<class C>
C		*LibHandler<C>::operator->()
{
	return _object;
}

template<class C>
const C	*LibHandler<C>::operator->() const
{
	return _object;
}

#endif /* !LIBHANDLER_HPP_ */
