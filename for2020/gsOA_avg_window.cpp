#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'stringFormattedWeeklyPrices' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts INTEGER_ARRAY dailyPrice as parameter.
 */

vector<string> stringFormattedWeeklyPrices(vector<int> dailyPrice) {
    int n = dailyPrice.size();
    vector<float> ans;
    float sum  = 0;
    for (int i = 0; i < 7; ++i) {
        sum += dailyPrice[i];
    }
    ans.push_back(roundf((sum/7)*100) / 100);
    for (int i = 7, begin = 0; i < n; i++, begin++) {
        sum -= dailyPrice[begin];
        sum += dailyPrice[i];
        ans.push_back(roundf((sum/7)*100) / 100);
    }

    int k = ans.size();
    vector<string> res(k);
    for (int i =0; i < k; ++i) {
        res[i] = to_string(ans[i]).substr(0, 4);
    }
    return res;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string dailyPrice_count_temp;
    getline(cin, dailyPrice_count_temp);

    int dailyPrice_count = stoi(ltrim(rtrim(dailyPrice_count_temp)));

    vector<int> dailyPrice(dailyPrice_count);

    for (int i = 0; i < dailyPrice_count; i++) {
        string dailyPrice_item_temp;
        getline(cin, dailyPrice_item_temp);

        int dailyPrice_item = stoi(ltrim(rtrim(dailyPrice_item_temp)));

        dailyPrice[i] = dailyPrice_item;
    }

    vector<string> result = stringFormattedWeeklyPrices(dailyPrice);
    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
