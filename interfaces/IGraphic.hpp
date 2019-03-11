/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Graphuc handler interface
*/

#ifndef IGRAPHIC_HPP_
    #define IGRAPHIC_HPP_

    #include "IDisplayable.hpp"

class IGraphic {
	public:

    virtual ~IGraphic() = default;

    virtual void    setEntity(int x, int y, IDisplayable &entity) = 0;
    virtual void    update() = 0;
    virtual void    setSize(int x, int y) = 0;

};

#endif /* !IGRAPHIC_HPP_ */
