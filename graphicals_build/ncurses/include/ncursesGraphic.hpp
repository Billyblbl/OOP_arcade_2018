/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Graphic handler ncurses
*/

#ifndef NCURSESGRAPHIC_HPP_
    #define NCURSESGRAPHIC_HPP_

    #include    "IGraphic.hpp"
    #include    "Types.hpp"
    #include    <ncurses.h>
    #include    <unordered_map>

class   ncursesGraphic : public IGraphic  {
    public:

    ncursesGraphic();
    ~ncursesGraphic();
    void            setEntity(float x, float y, IDisplayable &entity) override; // elle marche
    void            write(int x, int y, const std::string &text) override; //elle marche
    void            setSize(int x, int y) override;
    bool            update() override; //wrefresh
    void            clear() override; //wclear
    IDisplayable    *createDisplayable(const std::string &path) override; // elle marche
    bool            hasInput() override;
    int32_t         getInput() override;

    typedef std::unordered_map<int32_t, int32_t> translation;

    private:
    WINDOW*         win;
    Vector2<int>    size;
    int32_t         input;

    static const translation    Translator;

};

#endif /* !NCURSESGRAPHIC_HPP_ */
