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

///Loadable Game handler interface

///@class IGame
///Defines a game object that can be loaded and used for the purpose of the Arcade EPITECH project
class IGame {
	public:

    virtual ~IGame() = default;

    ///Special Keycode values

    ///Enum type of keycodes for special keys.
    ///These keycodes are more than 1 char wide in data size.
    ///As these values are also int32_t this list is not exhaustive as a list of valid keycode for
    ///a game implementation keybinds. Valid keycodes also include ASCII values for the corresponding
    ///characters
    enum KeyCode : int32_t {
        arrowUp = 0x415b1b,     ///<Keycode for the Up arrow key
        arrowDown = 0x425b1b,   ///<Keycode for the Down arrow key
        arrowRight = 0x435b1b,  ///<Keycode for the Right arrow key
        arrowLeft = 0x445b1b,   ///<Keycode for the Left arrow key
        home = 0x485b1b,        ///<Keycode for the Home key
        end = 0x465b1b,         ///<Keycode for the End key
        pageUp = 0x355b1b,      ///<Keycode for the Page up key
        pageDown = 0x365b1b     ///<Keycode for the Page down key
    };


    ///Runs 1 frame of the game

    ///An implementation of this API must put the general in loop game code in this function
    ///@param deltaT is The duration between last frame and this one,
    ///@param upTime is The duration from the start of the game up to now
    ///@return The status of the game, true if active, false if not and if the game object should be destroyed
    virtual bool    update(std::chrono::nanoseconds deltaT, std::chrono::seconds upTime) = 0;


    ///React to the key pressed

    ///Handle the reaction of the game to the input of a keycode
    ///@param key Keycode of the pressed key
    virtual void    handleKey(int32_t key) = 0;


    ///Gives a graphic handler to the game

    ///Select handler as the new graphic handler for the game object.
    ///The graphic object referenced by handler is required to exist until another call to setGraphic is finished
    ///@param handler Reference to a graphic handler object
    virtual void    setGraphic(IGraphic &handler) = 0;


    ///Event called when the game is enabled

    ///Called when the game is enabled by the core, such as when the core creates the game.
    ///Behavior is implementation defined
    virtual void    onEnable() = 0;


    ///Event called when the game is disabled

    ///Called when the game is disabled by the core, such as when the core changes to another game or before deleting the game.
    ///Behavior is implementation defined
    virtual void    onDisable() = 0;

};

#endif /* !IGAME_HPP_ */
