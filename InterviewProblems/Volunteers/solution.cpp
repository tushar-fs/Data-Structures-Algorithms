#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Question
{
    string id;
    vector<string> tags;
    string title;
};

struct Volunteer
{
    string name;
    vector<string> topics;
};

struct Assignment
{
    string questionId;
    string volunteerId;
};

vector<Assignment> createAssignment(vector<Question> &questions, vector<Volunteer> &volunteers)
{
    unordered_set<string> ques_solved;
    vector<Assignment> assignments;
    // since volunteers has a prioritized list of tags
    for (Volunteer volunteer : volunteers)
    {
        bool isVolunteerAssigned = false;
        for (string tag : volunteer.topics)
        {
            for (Question ques : questions)
            {
                if (ques_solved.count(ques.id))
                    continue;
                vector<string> quesTags = ques.tags;
                auto it = find(quesTags.begin(), quesTags.end(), tag);
                if (it != quesTags.end())
                {
                    ques_solved.insert(ques.id);
                    assignments.push_back({ques.id, volunteer.name});
                    isVolunteerAssigned = true;
                    break;
                }
            }
            if (isVolunteerAssigned)
                break;
        }
    }
    return assignments;
}

int main()
{
    // --- Input Data ---
    // Initialize the list of questions.
    vector<Question> questions = {
        {"0", {"mac", "vs code"}, "how to install vs code"},
        {"1", {"python", "ai"}, "my program is too slow"},
        {"2", {"c#", "game"}, "why is hitbox off by 2 pixels"},
        {"3", {"java", "oop"}, "dependency injection stack trace"},
        {"4", {"python", "networking"}, "socket.recv is freezing"},
        {"5", {"c++", "networking"}, "i have a memory leak"}};

    // Initialize the list of volunteers with their prioritized tags.
    vector<Volunteer> volunteers = {
        {"sam5k", {"python", "networking"}},
        {"djpat", {"ai"}},
        {"jessg", {"java", "networking"}},
        {"rayo", {"java", "networking"}}};

    // --- Function Call ---
    vector<Assignment> results = createAssignment(questions, volunteers);
    // --- Print Output ---
    // Display the final assignments in the requested format.
    cout << "[" << endl;
    for (size_t i = 0; i < results.size(); ++i)
    {
        cout << "  {'question': '" << results[i].questionId
             << "', 'volunteer': '" << results[i].volunteerId << "'}";
        if (i < results.size() - 1)
        {
            cout << ",";
        }
        cout << endl;
    }
    cout << "]" << endl;

    return 0;
}
