#include <vector>
#include <unordered_map>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

struct Orange {
    vector<Orange*> neighbours;
    bool isRotten;
    int distance;
    bool visited;
};

class Solution {
public:
    string xyToString(const int x, const int y) const {
        return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
    }

    // Runs recursive BFS on this node, and then
    // recursively runs on downstream nodes
    // which follow 2 conditions:
    // 1. Has larger current distance
    // 2. Is not a rotten node
    void runRecursiveBFS(Orange* root) {
        std::vector<Orange*> orangesToVisit;
        for(auto it = root -> neighbours.begin(); it != root -> neighbours.end(); it++) {
            if( (*it) -> distance > root -> distance + 1 && !(*it) -> isRotten ) {

                // If updating distance, add to list of nodes
                // to visit and set visited to true
                (*it) -> distance = root -> distance + 1;
                orangesToVisit.push_back(*it);
                (*it) -> visited = true;
            }
        }

        for(auto it = orangesToVisit.begin(); it != orangesToVisit.end(); it++) {
            runRecursiveBFS(*it);
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        const int HEIGHT = grid.size();
        const int WIDTH = grid[0].size();

        // Below are 2 data structures we maintain.
        // The first is a lookup from (x,y) string to
        // a Orange pointer. The second is a vector
        // containing pointers to rotten oranges.
        // The second one is mainly useful for
        // iterating through rotten oranges when
        // we want to update distances
        unordered_map<string, Orange*> xyToOranges;
        vector<Orange*> rottenOranges;

        // Start by parsing through the int grid
        // and creating all oranges and edges to
        // existing oranges
        for(int y = 0; y < grid.size(); y++ ) {
            for(int x = 0; x < grid[0].size(); x++) {
                if(grid[y][x] == 0) {
                    continue;
                }

                // If not empty, start by creating
                // orange
                Orange* newOrange = new Orange();
                newOrange -> isRotten = grid[y][x] == 2;
                // Set distance to int max
                newOrange -> distance = numeric_limits<int>::max();
                // Set visited to false
                newOrange -> visited = false;

                // Add to the xy lookup, and the rotten list
                // if applicable. If rotten, also set distance to
                // 0 and visited to true
                xyToOranges[xyToString(x, y)] = newOrange;
                if(newOrange -> isRotten) {
                    // If rotten, add to the rotten list
                    // and set visited to true
                    rottenOranges.push_back(newOrange);
                    newOrange -> distance = 0;
                    newOrange -> visited = true;
                }

                // Now, add all neighbour links, only doing
                // so if the neighbours are already in
                // the lookup

                // Top neighbour
                if( y >= 1 && xyToOranges.find( xyToString(x, y - 1) ) != xyToOranges.end() ) {
                    // Top neighbour isn't empty, so update
                    // links
                    xyToOranges.at(xyToString(x, y - 1)) -> neighbours.push_back( newOrange );
                    newOrange -> neighbours.push_back( xyToOranges.at(xyToString(x, y - 1)) );
                }

                // Right neighbour
                if( x < WIDTH - 1 && xyToOranges.find( xyToString(x + 1, y) ) != xyToOranges.end() ) {
                    // Right neighbour isn't empty, so update
                    // links
                    xyToOranges.at(xyToString(x + 1, y)) -> neighbours.push_back( newOrange );
                    newOrange -> neighbours.push_back( xyToOranges.at(xyToString(x + 1, y)) );
                }

                // Bottom neighbour
                if( y < HEIGHT - 1 && xyToOranges.find( xyToString(x, y + 1) ) != xyToOranges.end() ) {
                    // Bottom neighbour isn't empty, so update
                    // links
                    xyToOranges.at(xyToString(x, y + 1)) -> neighbours.push_back( newOrange );
                    newOrange -> neighbours.push_back( xyToOranges.at(xyToString(x, y + 1)) );
                }

                // Left neighbour
                if( x >= 1 && xyToOranges.find( xyToString(x - 1, y) ) != xyToOranges.end() ) {
                    // Left neighbour isn't empty, so update
                    // links
                    xyToOranges.at(xyToString(x - 1, y)) -> neighbours.push_back( newOrange );
                    newOrange -> neighbours.push_back( xyToOranges.at(xyToString(x - 1, y)) );
                }
            }
        }

        for(auto it = rottenOranges.begin(); it != rottenOranges.end(); it++) {
            runRecursiveBFS(*it);
        }

        // Now, iterate over all elements of the map, and return the maximum,
        // or return -1 if any neighbours aren't visited
        int currMax = 0;
        for(auto it = xyToOranges.begin(); it != xyToOranges.end(); it++) {
            currMax = max( it -> second -> distance, currMax );

            if( it -> second -> visited == false) {
                return -1;
            }
        }

        return currMax;
    }
};