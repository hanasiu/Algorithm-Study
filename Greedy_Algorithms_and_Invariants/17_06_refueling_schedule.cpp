#include <iostream>
#include <vector>

using namespace std;

const int kMPG = 20;

int FindAmpleCity(const vector<int> &gallons, const vector<int> &distances)
{
    int remaining_gallons = 0;
    struct CityAndRemainingGas
    {
        int city = 0, remaining_gallons = 0;
    };
    CityAndRemainingGas city_remaining_gallons_pair;
    const int num_cities = gallons.size();
    for (int i = 1; i < num_cities; ++i)
    {
        remaining_gallons += gallons[i - 1] - distances[i - 1] / kMPG;
        if (remaining_gallons < city_remaining_gallons_pair.remaining_gallons)
        {
            city_remaining_gallons_pair = {i, remaining_gallons};
        }
    }
    return city_remaining_gallons_pair.city;
}

int main()
{
    // Test case 1:
    vector<int> gallons1 = {50, 20, 5,30,25,10,10};
    vector<int> distances1 = {900,600,200,400,600,200,100 };
    int expected_output1 = 3;
    int actual_output1 = FindAmpleCity(gallons1, distances1);
    if (actual_output1 == expected_output1)
    {
        cout << "Test case 1 passed." << endl;
    }
    else
    {
        cout << "Test case 1 failed. Expected output: " << expected_output1
             << ". Actual output: " << actual_output1 << endl;
    }

    return 0;
}