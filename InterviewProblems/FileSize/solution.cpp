#include <string>
#include <vector>
#include <map>

using namespace std;

// Represents a single entry (file or directory) in the file system
class FileSystemNode
{
public:
    string name;
    bool isDirectory;

    // Only used if isDirectory = false
    int size;

    // Only used if isDirectory = true
    // Maps child name to the child node
    map<string, FileSystemNode *> children;

    FileSystemNode(string n, bool isDir, int s = -1)
    {
        name = n;
        isDirectory = isDir;
        size = s;
    }

    /**
     * Calculates the total size of the item at the given path.
     *
     * @param root The root node of the file system (this represents "/").
     * @param path The absolute path to the item (e.g., "/documents/report.pdf" or "/documents").
     * @return The total size of the item.
     * - If the path points to a FILE, return its individual size.
     * - If the path points to a DIRECTORY, return the sum of all
     * files and sub-directories it contains (recursively).
     * - If the path is invalid or does not exist, return -1.
     */
    int getTotalSize(FileSystemNode *root, string path)
    {
        // Your implementation goes here
        if (root == nullptr)
            return -1;
        FileSystemNode *root = getFileFromPath(path);
        return getTotalSizeImpl(root);
    }

    FileSystemNode *getFileFromPath(string &path)
    {
        int end = path.size() - 1;
        string fileName = "";
        while (path[end] != '/')
        {
            fileName += path[end];
            end--;
        }
        reverse(fileName.begin(), fileName.end());
        return this->children[fileName];
    }

    int getTotalSizeImpl(FileSystemNode *root)
    {
        if (root->size != -1)
            return root->size;
        int curSize = 0;
        for (auto x : root->children)
        {
            curSize += getTotalSizeImpl(x.second);
        }
        if (root->isDirectory)
            root->size = curSize;
        return curSize;
    }
};