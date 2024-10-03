#include "course.hxx"
#include <vector>

Course::Course(std::string name_,
               Posn<int> time_slot_,
               std::vector<std::string> prerequisites_,
               bool active_)
    : name_(name_),
      time_slot_(time_slot_),
      prerequisites_(prerequisites_),
      active_(active_)
{}

//  time slot
void
Course::set_time_slot(Posn<int> time_slot)
{
    time_slot_ = time_slot;
}

// sets course's status (active or not in sched)
void
Course::set_active(bool active)
{
    active_ = active;
}

// checks if course is active
bool
Course::is_active() const
{
    return active_;
}

// checks if current time slot is empty
bool
Course::is_empty() const
{
    return name_.empty();
}
