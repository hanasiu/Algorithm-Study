#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

string ShortestEquivalentPath(const string &path)
{
    if (path.empty())
    {
        throw invalid_argument("Emptystring is not a valid path.");
    }

    vector<string> path_names;

    if (path.front() == '/')
    {
        path_names.emplace_back("/");
    }

    stringstream ss(path);
    string token;
    while (getline(ss, token, '/'))
    {
        if (token == "..")
        {

            if (path_names.empty() || path_names.back() == "..")
            {
                path_names.emplace_back(token);
            }
            else
            {
                if (path_names.back() == "/")
                {
                    throw invalid_argument("Path error");
                }
                path_names.pop_back();
            }
        }
        else if (token != "." && token != "")
        {
            path_names.emplace_back(token);
        }
    }

    string result;
    if (!path_names.empty())
    {
        result = path_names.front();
        for (int i = 1; i < path_names.size(); ++i)
        {
            if (i == 1 && result == "/")
            {
                result += path_names[i];
            }
            else
            {
                result += "/" + path_names[i];
            }
        }
    }
    return result;
}

int main()
{
    const string example = "sc//./../tc/awk/././";
    string result = ShortestEquivalentPath(example);

    string example2 = "/usr/lib/../bin/gcc";
    string example3 = "scripts//./../scripts/awkscripts/././";
    string result2 = ShortestEquivalentPath(example2);
    string result3 = ShortestEquivalentPath(example3);
    cout << result << endl << result2 << endl << result3 << endl;
    return 0;
}