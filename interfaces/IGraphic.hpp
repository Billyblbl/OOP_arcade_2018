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

    virtual void            setEntity(float x, float y, IDisplayable &entity) = 0;
    virtual void            write(int x, int y, const std::string &text) = 0;
    virtual void            setSize(int x, int y) = 0;
    virtual void            update() = 0;
    virtual void            clear() = 0;
    virtual IDisplayable    *createDisplayable(const std::string &name) = 0;

};

#endif /* !IGRAPHIC_HPP_ */
