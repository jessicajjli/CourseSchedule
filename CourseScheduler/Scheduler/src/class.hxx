#pragma once

#include <iostream>
#include <vector>


enum class Course_type
{
    lecture,
    lab,
    seminar,
    workshop,
    none,
};


class Course
{
private:
    std::string name_;
    Course_type type_;
    int course_id_;
    int credits_; 
    std::vector<int> enrolled_students_;

public:
    Course(std::string name, Course_type type, int course_id, int credits);

    // getters
    std::string get_name() const;
    Course_type get_type() const;
    int get_course_id() const;
    int get_credits() const;
    std::vector<int> get_enrolled_students() const;


    void add_student(int student_id);
    void remove_student(int student_id);
};


class Student
{
private:
    std::string name_;
    int student_id_;
    std::vector<int> enrolled_courses_;

public:
    Student(std::string name, int student_id);


    std::string get_name() const;
    int get_student_id() const;
    std::vector<int> get_enrolled_courses() const;


    void enroll_in_course(int course_id);
};


class Schedule
{
private:
    int student_id_;
    std::vector<Course> courses_; 

public:
    Schedule(int student_id);

    void add_course(Course const& course);
    std::vector<Course> get_courses() const;
};

