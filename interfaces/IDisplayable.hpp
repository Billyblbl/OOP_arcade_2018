/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** displayable entity interface
*/

#ifndef IDISPLAYABLE_HPP_
	#define IDISPLAYABLE_HPP_

	#include <string>

///Displayable entity interface

///@class IDisplayable
///Defines an entity object that can be displayed.
///Such entity can have several states, those states are defined in a .entity file
///following the definition of the format given by the A.L.P-a.C.A reference.
///An implementation of this API is responsible for providing a corresponding construction mecanism.
class IDisplayable {
	public:

	virtual ~IDisplayable() = default;

	///Increment the Displayable entity's state.

	///Puts the Displayable entity in its next state.
	///States are ordered as declared in the corresponding .entity file.
	///Wraps around to the first state if used at the end of the state list.
	///@return A reference to itself after state incrementation
	virtual IDisplayable		&operator++() = 0;


	///Decrement the Displayable entity's state.

	///Puts the Displayable entity in its previous state.
	///States are ordered as declared in the corresponding .entity file.
	///Wraps around to the last state if used at the beggining of the state list.
	///@return A reference to itself after state decrementation
	virtual IDisplayable		&operator--() = 0;


	///Puts the Displayable entity in the state associated with stateName

	///@param stateName Name of the desired state for the Displayable entity
	virtual void    			setState(const std::string &stateName) = 0;


	///Put the Displayable entity in the stateId'th state

	///States are ordered as declared in the corresponding .entity file.
	///@param stateId Index of the desired state for the Displayable entity
	virtual void				setState(std::size_t stateId) = 0;


	///State name accessor

	///Access the current state and returns its name
	///@return Name of the current state
	virtual const std::string	&getState() const = 0;

};

#endif /* !IDISPLAYABLE_HPP_ */
