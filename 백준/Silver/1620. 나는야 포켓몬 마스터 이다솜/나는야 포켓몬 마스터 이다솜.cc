#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool is_number(string s)
{
  for (char c : s)
    if (!isdigit(c))
      return false;
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  unordered_map<string, int> name_to_id;
  unordered_map<int, string> id_to_name;

  int N, M;
  cin >> N >> M;

  for (int i = 1; i <= N; i++)
  {
    string name;
    cin >> name;

    name_to_id.insert({name, i});
    id_to_name.insert({i, name});
  }

  for (int i = 0; i < M; i++)
  {
    string name_or_id;
    cin >> name_or_id;

    if (is_number(name_or_id))
      cout << id_to_name[stoi(name_or_id)] << '\n';
    else
      cout << name_to_id[name_or_id] << '\n';
  }

  return 0;
}