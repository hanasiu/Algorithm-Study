#include <vector>
#include <deque>
#include <iostream>
#include <queue>

using namespace std;

#include <random>

using namespace std;

void CreateRandomImage(int width, int height, vector<deque<bool>> *image_ptr)
{
    vector<deque<bool>> &image = *image_ptr;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);

    for (int y = 0; y < height; ++y)
    {
        deque<bool> row;
        for (int x = 0; x < width; ++x)
        {
            row.push_back(dis(gen));
        }
        image.push_back(row);
    }
}

void FlipColor(int x, int y, vector<deque<bool>> *image_ptr)
{
    vector<deque<bool>> &image = *image_ptr;
    const bool color = image[x][y];

    queue<pair<int, int>> q;
    image[x][y] = !color;

    q.emplace(x, y);
    while (!q.empty())
    {
        const auto [x, y] = q.front();
        q.pop();
        for (const auto &[next_x, next_y] : initializer_list<pair<int, int>>{
                 {x, y + 1}, {x, y - 1}, {x + 1, y}, {x - 1, y}})
        {
            if (next_x >= 0 && next_x < image.size() && next_y >= 0 &&
                next_y < image[next_x].size() && image[next_x][next_y] == color)
            {
                image[next_x][next_y] = !color;
                q.emplace(next_x, next_y);
            }
        }
    }
}

void FlipColorDepth(int x, int y, vector<deque<bool>> *image_ptr)
{
    vector<deque<bool>> &image = *image_ptr;
    const bool color = image[x][y];
    image[x][y] = !color;

    for (const auto &[next_x, next_y] : initializer_list<pair<int, int>>{
             {x, y + 1}, {x, y - 1}, {x + 1, y}, {x - 1, y}})
    {
        if (next_x >= 0 && next_x < image.size() && next_y >= 0 &&
            next_y < image[next_x].size() && image[next_x][next_y] == color)
        {
            FlipColor(next_x, next_y, &image);
        }
    }
}

int main()
{
    vector<deque<bool>> image;
    CreateRandomImage(10, 10, &image);

    // print out the resulting image
    for (const auto &row : image)
    {
        for (const auto &pixel : row)
        {
            cout << (pixel ? 'X' : '.');
        }
        cout << endl;
    }
    cout << endl;
    FlipColor(5, 5, &image);

    for (const auto &row : image)
    {
        for (const auto &pixel : row)
        {
            cout << (pixel ? 'X' : '.');
        }
        cout << endl;
    }
    cout << endl;
    FlipColorDepth(2, 8, &image);

      for (const auto &row : image)
    {
        for (const auto &pixel : row)
        {
            cout << (pixel ? 'X' : '.');
        }
        cout << endl;
    }
    return 0;
}