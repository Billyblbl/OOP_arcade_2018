/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** game interface
*/

#ifndef IGAME_HPP_
    #define IGAME_HPP_

    #include <functional>
    #include <chrono>
    #include "IGraphic.hpp"

class IGame {
	public:

    virtual ~IGame() = default;

    typedef std::function<void ()>  Action;

    virtual bool update(std::chrono::nanoseconds deltaT) = 0;
    virtual const Action  &getKeybind(char key) const = 0;
    virtual void    setGraphic(IGraphic &handler) = 0;

};

#endif /* !IGAME_HPP_ */
