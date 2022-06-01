#include <algorithm>
#include <iterator>
#include <vector>

using std::vector;

class Team {
  public:
    explicit Team(const vector<int>& height) {
      transform(begin(height), end(height), back_inserter(players_),
                [](int h) {return Player{h}; });
    }
  
  //Checks if team0 can be placed in front of team1.
  static bool ValidPlacementExists(const Team& team0, const Team& team1) {
    vector<PLayer> team0_sorted(team0.SortPlayersByHeight());
    vector<PLayer> team1_sorted(team1.SortPlayersByHeight());
    for( int i = 0; i < size(team0_sorted) && i < size(team1_sorted); ++i) {
      if(!(team0_sorted[i] < team1_sorted[i])) {
        //team0_sorted[i] cannot be placed behind team1_sorted[i].
        return false;
      }
    }
    return true;
  }
  
  private:
  struct Player {
    bool operator <(const Player& that) const { return height < that. height; }
    int height;
  };
  
  vector<Player> SortPlayersByHeight() const {
    vector<Player> sorted_players(players_);
    sort(begin(sorted_players), end(sorted_players));
    return sorted_players;
  }
  
  vector<Player> players_;
};


                
