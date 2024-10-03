#include "model.hxx"


Model::Model()
    : course_selected_(Course("", {-1, -1}, {}, false))
{
    //8x5 grid 8hrs 5 days
    for (int i = 0; i < 5; i++) {
        schedule_.push_back(std::vector<Course>());
    }

    for (std::vector<Course>& day: schedule_) {
        for (int i = 0; i < 8; i++) { // 8 timeslots in a day
            day.push_back(Course("", {i, 0}, {}, false)); // Empty slots
        }
    }
}

// gets course
Course
Model::operator[](Position pos) const
{
    return schedule_[pos.x][pos.y];
}


bool
Model::add_course(Course course, Position pos)
{
    if (schedule_[pos.x][pos.y].is_empty()) {
        schedule_[pos.x][pos.y] = course;
        return true;
    }
    return false; // Slot already occupied
}


void
Model::reset_course_selected()
{
    course_selected_ = Course("", {-1, -1}, {}, false);
}


void
Model::change_turn()
{
    if (current_turn_ == 1) {
        current_turn_ = 0;
    } else {
        current_turn_ = 1;
    }
}
