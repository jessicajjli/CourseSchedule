#include "controller.hxx"

// constructor initializing
Controller::Controller()
    : model_(),
      view_(model_)
{}

//current state
void Controller::draw(Sprite_set& set)
{
    view_.draw(set, mouse_pos);
}

void Controller::on_key(Key k)
{
    if (Key::code('q') == k) {
        quit();
    }
}

View::Dimensions Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

void Controller::on_mouse_move(Posn<int> pos)
{
    mouse_pos = pos;
}

void Controller::on_mouse_up(Mouse_button m, Posn<int> pos)
{
    if (!model_.is_schedule_finalized()) {
        Posn<int> timeslot_pos = view_.screen_to_board(pos);
        Position board_pos = {timeslot_pos.x, timeslot_pos.y};

        // if valid timeslot is selected task assignment
        if (model_.is_valid_timeslot(board_pos)) {
            model_.set_selected_timeslot(board_pos);
        }

        // if task selected, timeslot available schedule
        if (model_.has_selected_task() &&
            model_.is_timeslot_available(model_.get_selected_timeslot())) {
            model_.schedule_task(model_.get_selected_task(), 
                                 model_.get_selected_timeslot());
        }
    }
}

