#pragma once

#include "model.hxx"
#include "view.hxx"
#include <utility>

class Controller : public Abstract_scheduler
{
public:
    Controller();

protected:
    void draw(Sprite_set& set) override;
    View::Dimensions initial_window_dimensions() const override;
    void on_mouse_up(Mouse_button, Posn<int>) override;
    void on_mouse_move(Posn<int>) override;
    void on_key(Key) override;

private:
    Model model_;
    View view_;
    Posn<int> mouse_pos = {0, 0};
};
