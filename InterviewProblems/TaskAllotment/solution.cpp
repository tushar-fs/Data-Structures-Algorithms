#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

/**
 * You are designing a task scheduler for a distributed system.
 * You have a list of tasks and a list of available servers.
 * Each task requires a certain amount of ram (in GB) and a specific os ("linux" or "windows").
 * Each server has a total ramCapacity, a current ramUsed, an os, and a list of supportedServices (e.g., "database", "cache", "auth"). Tasks have a requiredService.

 * Write a function that assigns each task to a capable server.
 * A server is capable if it runs the correct OS, has enough available RAM for the task,
 * and supports the required service. The goal is to assign as many tasks as possible.
 */

struct Task
{
    int id;
    int ram;
    string os;
    string requiredService;
};

struct Server
{
    string id;
    string os;
    int ramCapacity;
    int ramUsed;
    vector<string> supportedServices;
};

struct Allotment
{
    int taskId;
    string serverId;
};

vector<Allotment> allotTasks(vector<Task> &tasks, vector<Server> &servers)
{
    vector<Allotment> allotedTasks;

    unordered_map<string, unordered_map<string, bool>> serverToSupportedServicesMap;

    for (Server &server : servers)
    {
        for (string service : server.supportedServices)
        {
            serverToSupportedServicesMap[server.id][service] = true;
        }
    }

    for (const Task &task : tasks)
    {
        for (Server &curServer : servers)
        {
            int ramAvailable = curServer.ramCapacity - curServer.ramUsed;
            auto it = serverToSupportedServicesMap[curServer.id].find(task.requiredService);
            if (task.os == curServer.os && task.ram <= ramAvailable && it != serverToSupportedServicesMap[curServer.id].end())
            {
                curServer.ramUsed += task.ram;
                allotedTasks.push_back({task.id, curServer.id});
                break;
            }
        }
    }

    return allotedTasks;
}

int main()
{
    vector<Task> tasks = {
        {1, 8, "linux", "database"},
        {2, 16, "linux", "cache"},
        {3, 4, "windows", "auth"}};

    vector<Server> servers = {
        {"sv1", "linux", 32, 20, {"database", "auth"}},
        {"sv2", "linux", 16, 0, {"cache"}},
        {"sv3", "windows", 8, 5, {"auth", "database"}}};

    vector<Allotment> results = allotTasks(tasks, servers);

    for (Allotment x : results)
    {
        cout << x.taskId << " " << x.serverId << endl;
    }
}