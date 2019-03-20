/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** displayable entity interface
*/

#ifndef IDISPLAYABLE_HPP_
	#define IDISPLAYABLE_HPP_

class IDisplayable {
	public:

	virtual ~IDisplayable() = default;

	//Put the Displayable entity in the state associated with [stateName]
	virtual void    			setState(const std::string &stateName) = 0;

	//Put the Displayable entity in the stateId'th state as ordered in the corresponding .entity file
	virtual void				setState(std::size_t stateId) = 0;

	//Returns the name of the current state
	virtual const std::string	&getState() const = 0;

	//Puts the Displayable entity in the next state as ordered in the corresponding .entity file
	//Wraps around to the first state if used at the end of the state list
	virtual IDisplayable		&operator++() = 0;

	//Puts the Displayable entity in the previous state as ordered in the corresponding .entity file
	//Wraps around to the last state if used at the begining of the state list
	virtual IDisplayable		&operator--() = 0;

};

#endif /* !IDISPLAYABLE_HPP_ */
