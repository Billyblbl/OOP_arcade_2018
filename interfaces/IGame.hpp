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

    enum KeyCode : int32_t {
        arrowUp = 0x415b1b,
        arrowDown = 0x425b1b,
        arrowRight = 0x435b1b,
        arrowLeft = 0x445b1b,
        home = 0x485b1b,
        end = 0x465b1b,
        pageUp = 0x355b1b,
        pageDown = 0x365b1b
    };

    virtual bool            update(std::chrono::nanoseconds deltaT) = 0;
    virtual const Action    &getKeybind(int32_t key) const = 0;
    virtual void            setGraphic(IGraphic &handler) = 0;

};

#endif /* !IGAME_HPP_ */
