void fill_prices(vector<string> &p_date, vector<float> &prices)
{
    ifstream data("../data.csv");
    string tmp;
    float conv;
    std::stringstream f_nb;

    while (std::getline(data, tmp))
    {
        // cout << tmp << endl;
        p_date.push_back(tmp.substr(0, 10));
        f_nb << tmp.substr(11, tmp.size());
        f_nb >> conv;
        cout << tmp.substr(11, tmp.size()) << endl;
    }

    // for (vector<string>::iterator it = p_date.begin(); it != p_date.end(); it++)
    // {
    //     cout << *it << endl;
    // }
    // return;
}