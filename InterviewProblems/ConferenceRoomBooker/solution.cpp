#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Meeting
{
    int startTime;
    int endTime;
    vector<string> features;
};

struct Room
{
    string id;
    vector<string> features;
};

int allocateMeetingRooms(vector<Meeting> &meetings, vector<Room> &rooms)
{

    sort(meetings.begin(), meetings.end(), [](Meeting &a, Meeting &b)
         { return a.startTime <= b.startTime; });

    sort(rooms.begin(), rooms.end(), [](Room &a, Room &b)
         { return a.features.size() < b.features.size(); });

    unordered_map<string, unordered_set<string>> roomToFeatureMap;

    for (Room &room : rooms)
    {
        for (string feature : room.features)
        {
            roomToFeatureMap[room.id].insert(feature);
        }
    }

    // create min heap
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    vector<string> freeRooms;
    for (Room &room : rooms)
    {
        freeRooms.push_back(room.id);
    }

    for (Meeting &meeting : meetings)
    {
        if (!pq.empty() && meeting.startTime >= pq.top().first)
        {
            freeRooms.push_back(pq.top().second);
            pq.pop();
        }
        bool roomBooked = false;
        for (string roomId : freeRooms)
        {
            // now check if all features equipped
            bool isRoomBooked = true;
            for (string feature : meeting.features)
            {
                if (!roomToFeatureMap[roomId].count(feature))
                {
                    isRoomBooked = false;
                    break;
                }
            }
            if (isRoomBooked)
            {
                roomBooked = true;
                // delete occ room from freeRooms vector
                pq.push({meeting.endTime, roomId});
                break;
            }
        }
        if (!roomBooked)
            return -1;
    }

    return pq.size();
}

int main()
{
    // Meetings: {startTime, endTime, {features}}
    vector<Meeting> meetings = {
        {1, 5, {"projector"}},
        {2, 4, {"whiteboard"}},
        {6, 8, {"projector", "whiteboard"}},
        {3, 6, {"projector"}}};

    // Rooms: {id, {features}}
    vector<Room> rooms = {
        {"room1", {"projector", "whiteboard"}},
        {"room2", {"projector"}}};

    return 0;
}