#include "model.hxx"
#include <catch.hxx>

struct Test_access
{
    Model& model;

    explicit Test_access(Model&);

    void add_course(std::string const& course_name, Course_type type, int credits);
    void enroll_student(int student_id, int course_id);
};

Test_access::Test_access(Model& model)
        : model(model)
{ }

void
Test_access::add_course(std::string const& course_name, Course_type type, int credits)
{
    Course course(course_name, type, model.get_all_courses().size(), credits);
    model.add_course(course);
}

void
Test_access::enroll_student(int student_id, int course_id)
{
    model.enroll_student_in_course(student_id, course_id);
}

TEST_CASE("Add and retrieve course")
{
    Model model;
    Test_access access(model);

    access.add_course("Computer Science 101", Course_type::lecture, 3);

    CHECK(model.get_all_courses().size() == 1);
    Course added_course = model.get_all_courses()[0];

    CHECK(added_course.get_name() == "Computer Science 101");
    CHECK(added_course.get_type() == Course_type::lecture);
    CHECK(added_course.get_credits() == 3);
}

TEST_CASE("Enroll student in a course")
{
    Model model;
    Test_access access(model);

    access.add_course("Mathematics 101", Course_type::lecture, 4);
    Student student("Alice", 1);
    model.add_student(student);

    access.enroll_student(1, 0);

    std::vector<int> enrolled_students = model.get_all_courses()[0].get_enrolled_students();
    CHECK(enrolled_students.size() == 1);
    CHECK(enrolled_students[0] == 1);
}

TEST_CASE("Generate schedule for student")
{
    Model model;
    Test_access access(model);

    access.add_course("Physics 101", Course_type::lecture, 3);
    access.add_course("Chemistry 101", Course_type::lab, 3);
    Student student("Bob", 2);
    model.add_student(student);

    access.enroll_student(2, 0);
    access.enroll_student(2, 1);

    model.generate_schedule_for_student(2);

    Schedule schedule = model.get_student_schedule(2);
    std::vector<Course> courses = schedule.get_courses();

    CHECK(courses.size() == 2);
    CHECK(courses[0].get_name() == "Physics 101");
    CHECK(courses[1].get_name() == "Chemistry 101");
}

TEST_CASE("Remove course from the system")
{
    Model model;
    Test_access access(model);

    access.add_course("History 101", Course_type::seminar, 2);

    CHECK(model.get_all_courses().size() == 1);

    model.remove_course(0);

    CHECK(model.get_all_courses().size() == 0);
}

TEST_CASE("Illegal enrollment handling")
{
    Model model;
    Test_access access(model);

    access.add_course("Biology 101", Course_type::lecture, 3);
    Student student("Charlie", 3);
    model.add_student(student);

    bool enrollment_result = model.enroll_student_in_course(999, 0);
    CHECK(enrollment_result == false);

    enrollment_result = model.enroll_student_in_course(3, 999);
    CHECK(enrollment_result == false);
}

