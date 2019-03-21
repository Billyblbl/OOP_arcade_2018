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

	//board cells coordinates definition: (for cells defined as [x, y])
	// [0, 0][1, 0][2, 0]...[i, 0]
	// [0, 1][1, 1][2, 1]...[i, 1]
	// ...
	// [0, j][1, j]   ...   [i, j]

	//Draws entity on the screen defined by the handler
	//x & y are the coordinates in "cells" of the board
	virtual void            setEntity(float x, float y, IDisplayable &entity) = 0;

	//Writes text on the screen defined by the handler
	//x & y are the coordinates in "cells" of the board
	virtual void            write(int x, int y, const std::string &text) = 0;

	//Defines board size in "cells"
	virtual void            setSize(int x, int y) = 0;

	//Updates screen with all entities drawn on it with "setEntity" & "write"
	virtual void            update() = 0;

	//Clear the screen defined by the handler
	virtual void            clear() = 0;

	//Create a displayable entity that the handler can draw with setEntity
	// ATTENTION the returned object need to be deleted before the handler is destroyed
	// as the destruction of said object will call the implementation side destructor
	// which may not be defined anymore after handler destruction and result in undefined behavior
	virtual IDisplayable    *createDisplayable(const std::string &name) = 0;

	//checks if an input is available for the window of the graphic handler
	virtual bool            hasInput() = 0;

	//get the current input of the graphic handler (has to be called only if hasInput returned true)
	virtual int32_t         getInput() = 0;

};

#endif /* !IGRAPHIC_HPP_ */
