#pragma once

#include "model.hxx"


static const int cell_size = 50;

class View
{
public:
    using Dimensions = Dims<int>;
    using Position = Posn<int>;

    explicit View(Model const& model);

    Dimensions initial_window_dimensions() const;
    void draw(Sprite_set& set, Position mouse_pos);

    Position screen_to_board(Position screen_pos) const;
    Position board_to_screen(Position board_pos) const;

    void draw_course(Position pos, std::string const& course_name, Sprite_set& set) const;
    void draw_student(Position pos, std::string const& student_name, prite_set& set) const;
    void draw_schedule(Position pos, Schedule const& schedule, Sprite_set& set) const;
    
private:
    Model const& model_;

    Rectangle_sprite const course_tile_;
    Rectangle_sprite const student_tile_;
    Rectangle_sprite const schedule_tile_;
};
