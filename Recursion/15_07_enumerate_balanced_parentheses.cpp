#include <iostream>

using namespace std;

void DirectedGenerateBalancedParentheses(int num_left_parens_needed, int num_right_parens_needed,
                                         const string &valid_prefix, vector<string> *result)
{
    if (!num_right_parens_needed)
    {
        result->emplace_back(valid_prefix);
        return;
    }

    if (num_left_parens_needed > 0)
    {
        DirectedGenerateBalancedParentheses(num_left_parens_needed - 1, num_right_parens_needed,
                                            valid_prefix + '(', result);
    }

    if (num_left_parens_needed < num_right_parens_needed)
    {
        DirectedGenerateBalancedParentheses(num_left_parens_needed, num_right_parens_needed - 1,
                                            valid_prefix + ')', result);
    }
}

vector<string> GenerateBalancedParentheses(int num_pairs) {
    vector<string> result;
    DirectedGenerateBalancedParentheses(num_pairs, num_pairs, "", &result);
    return result;
}

int main() {
    vector<string> i = GenerateBalancedParentheses(4);
    for(auto k : i) {
        cout << k << endl;
    }
    return 0;
}