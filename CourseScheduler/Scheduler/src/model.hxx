#pragma once

#include <list>
#include <vector>
#include "class.hxx"

using Position = Posn<int>;

class Model
{
private:
    std::vector<Course> courses_; // available courses
    std::vector<Student> students_; // students enrolled
    std::vector<Schedule> schedules_; 
    int selected_course_; 
    int current_student_;

public:
    Model();
    
    // interact with the scheduler
    void add_course(Course const& course);
    void remove_course(int course_id);
    void enroll_student_in_course(int student_id, int course_id);
    void generate_schedule_for_student(int student_id);
    
    // getters
    std::vector<Course> get_all_courses() const;
    std::vector<Student> get_all_students() const;
    Schedule get_student_schedule(int student_id) const;
    
    int get_selected_course() const;
    int get_current_student() const;
};
