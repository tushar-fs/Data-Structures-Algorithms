#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

/**
 * You are building a course registration system. You have a list of students and a list of courses.
 * Each student has a list of completedPrerequisites. Each course has a list of requiredPrerequisites
 * and a limited capacity. Students also have a list of courses they want to take, in order of preference.
 *
 * Write a function that assigns students to courses, respecting their preferences and ensuring
 * they meet all prerequisites. A student can only be enrolled in one course, and
 * a course cannot exceed its capacity.
 * {
    "students": [
        { "id": "anna", "completed": ["CS101", "MATH100"], "preferences": ["CS202", "CS201"] },
        { "id": "bob", "completed": ["CS101"], "preferences": ["CS201", "CS202"] }
    ],
    "courses": [
        { "id": "CS201", "required": ["CS101"], "capacity": 1 },
        { "id": "CS202", "required": ["CS101", "MATH100"], "capacity": 2 }
    ]
 * }

 * output: [{"anna": "CS202"}, {"Bob": "CS201"}]
 */

struct Student
{
    string id;
    vector<string> completed;
    vector<string> preferences;
};

struct Course
{
    string id;
    vector<string> required;
    int capacity;
};

struct Allotment
{
    string courseId;
    string studentId;
};

vector<Allotment> allotCourses(vector<Student> &students, vector<Course> &courses)
{
    vector<Allotment> allotments;
    // students have courses in order of preference
    // check capacity of the course & check if the student has completed the pre-req of a course before taking
    // Assign the course to the student

    unordered_map<string, unordered_map<string, bool>> studentToCompletedCourseMap;
    for (Student &student : students)
    {
        for (string completedCourse : student.completed)
        {
            studentToCompletedCourseMap[student.id][completedCourse] = 1;
        }
    }

    unordered_map<string, Course *> courseMap;
    for (Course &course : courses)
    {
        courseMap[course.id] = &course;
    }

    for (Student student : students)
    {
        vector<string> completedCourses = student.completed;
        for (string preferredCourse : student.preferences)
        {
            Course *course = courseMap[preferredCourse];

            // check for course capacity
            if (course->capacity == 0)
                continue;

            // check for pre-reqs
            bool requirementsCleared = true;
            for (string preReq : course->required)
            {
                if (studentToCompletedCourseMap[student.id].find(preReq) == studentToCompletedCourseMap[student.id].end())
                {
                    requirementsCleared = false;
                    break;
                }
            }

            if (requirementsCleared)
            {
                course->capacity--;
                allotments.push_back({course->id, student.id});
                break;
            }
        }
    }

    return allotments;
}

int main()
{
    vector<Student> students = {
        {"anna", {"CS101", "MATH100"}, {"CS202", "CS201"}},
        {"bob", {"CS101"}, {"CS201", "CS202"}}};
    vector<Course> courses = {{"CS201", {"CS101"}, 1},
                              {"CS202", {"CS101", "MATH100"}, 2}};
    vector<Allotment> allotments = allotCourses(students, courses);
    for (Allotment allotment : allotments)
    {
        cout << allotment.studentId << " " << allotment.courseId << endl;
    }
    return 0;
}