#include "view.hxx"

View::View(Model const& model)
    : model_(model)
{}

void View::draw(Sprite_set& set, Posn<int> mouse_pos)
{
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            // Add code to visualize each timeslot
            Posn<int> pos = {x * cell_size_, y * cell_size_};
            set.add_sprite(timeslot_sprite_, pos);
        }
    }

    //tasks n scheduled timeslots
    for (const Task& task : model_.get_scheduled_tasks()) {
        Posn<int> task_pos = {
            task.timeslot.x * cell_size_,
            task.timeslot.y * cell_size_
        };
        set.add_sprite(task_sprite_, task_pos);
    }
}

Posn<int> View::screen_to_board(ge211::Posn<int> screen_pos) const
{
    return {screen_pos.x / cell_size_, screen_pos.y / cell_size_};
}

View::Dimensions View::initial_window_dimensions() const
{
    return {cell_size_ * 8, cell_size_ * 8};
}

