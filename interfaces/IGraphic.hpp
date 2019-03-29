/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Graphuc handler interface
*/

#ifndef IGRAPHIC_HPP_
	#define IGRAPHIC_HPP_

	#include <string>
	#include "IDisplayable.hpp"

///Loadable Graphic handler interface

///@class IGraphic
///Defines a graphic handler object that can be loaded and used for the purpose of the Arcade EPITECH project.
///Implementation of this API is responsible for defining a display for the user, using a virtual board of cells
///whose origin is the upleft corner of the display, with the X axis increasing to the right and the Y axis
///increasing downward
class IGraphic {
	public:

	virtual ~IGraphic() = default;

	///Draws entity on the screen defined by the handler

	///Draws an entity at a position defined by the given coordinates x & y
	///Units of these coordinate correspond to the dimensions of a cell on the display of the handler
	///@param x Position on the X axis of where to draw the entity
	///@param y Position on the Y axis of where to draw the entity
	///@param entity Displayable entity to be drawn
	virtual void            setEntity(float x, float y, IDisplayable &entity) = 0;


	///Writes text on the screen defined by the handler

	///Writes text at a position defined by the given coordinates x & y
	///Units of these coordinate correspond to the dimensions of a cell on the display of the handler
	///@param x Position on the X axis of where to write the text
	///@param y Position on the Y axis of where to write the text
	///@param text Text to be written
	virtual void            write(int x, int y, const std::string &text) = 0;


	///Defines board size

	///Set the virtual board of the handler to the size given in arguments, with units being cells of the board
	///@param x Width of the new virtual board
	///@param y Height of the new virtual board
	virtual void            setSize(int x, int y) = 0;


	///Update the frame on the display

	///Updating of the frame draw visually on the display for the user every entities & texts drawn on the board
	///@return The status of the display, true if its still open, false if a user or else closed it and the application should close
	virtual bool            update() = 0;


	///Clear the virtual board defined by the handler

	///Erases every entities and texts drawn on the virtual board defined by the handler
	virtual void            clear() = 0;


	///Displayable entity factory

	///Creates a displayable entity that the handler can draw with setEntity form the .entity file given as argument
	///@param path Path to the .entity file to be used for entity construction
	///@return Constructed Displayable entity
	///@warning The returned object needs to be deleted before the handlerthat gave it is destroyed
	///as the destruction of said object will call the implementation side destructor which may not be
	///defined anymore after handler destruction and result in undefined behavior
	virtual IDisplayable    *createDisplayable(const std::string &path) = 0;


	///Checks for input in the display of the graphic handler

	///@return true if some input is ready, false otherwise
	virtual bool            hasInput() = 0;


	///Input getter

	///Get the current input of the display defined by the graphic handler.
	///As fetching method is implementation dependant, calling this method without a positive
	///return of hasInput result in undefined behavior
	///@return The keycode of the current input in the display
	virtual int32_t         getInput() = 0;

};

#endif /* !IGRAPHIC_HPP_ */
