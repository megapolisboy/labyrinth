#include <iostream>
using namespace std;
bool lab[5][5] = {1, 1, 0, 0, 0,
                  0, 1, 1, 0, 0,
                  0, 0, 1, 1, 1,
                  0, 0, 0, 0, 1,
                  0, 0, 0, 0, 1};

struct Coordinate{
    int x;
    int y;

    Coordinate(int x, int y){
        this->x = x;
        this->y = y;
    }
};

struct Path{
    Coordinate path[15] = {Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0)};
    int length = 0;

    Path(){
    }

    void addToPath(Coordinate c){
        path[length] = c;
        length++;
    }

    void removeFromPath(){
        if(length > 0){
            length--;
        }
    }
};

bool isValid(Coordinate c){
    return (c.x >= 0 && c.x < 5 && c.y >= 0 && c.y < 5 && lab[c.x][c.y]);
}

Path findPath(Coordinate coord, Path path){
    int x = coord.x;
    int y = coord.y;
    if(x == 4 && y == 4){
        return path;
        cout << "Done";
    }

    Coordinate c1 = Coordinate(x+1, y);
    Coordinate c2 = Coordinate(x-1, y);
    Coordinate c3 = Coordinate(x, y+1);
    Coordinate c4 = Coordinate(x, y-1);

    if(isValid(c1)){
        path.addToPath(c1);
        lab[x][y] = 0;
        return findPath(c1, path);
    }

    if(isValid(c2)){
        path.addToPath(c2);
        lab[x][y] = 0;
        return findPath(c2, path);
    }

    if(isValid(c3)){
        path.addToPath(c3);
        lab[x][y] = 0;
        return findPath(c3, path);
    }

    if(isValid(c4)){
        path.addToPath(c4);
        lab[x][y] = 0;
        return findPath(c4, path);
    }
}

int main() {
    Path path = findPath(Coordinate(0, 0),Path());
    for (int i = 0; i < path.length; i++){
        cout << path.path[i].x << " " << path.path[i].y << endl;
    }
}