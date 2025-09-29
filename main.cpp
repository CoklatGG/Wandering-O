#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
#include<vector>

bool playing = 1;
class Vector2 {
    public:
        float x;
        float y;
        
        
        Vector2(float _x, float _y) {
            x = _x;
            y = _y;    
        }


        bool operator==(Vector2 const& other) {
            return (x == other.x) && (y == other.y);
        }
};


class Player {
    public:
        Vector2 location = Vector2(0, 0);
        Player(Vector2 _loc) {
            location = _loc;
        }
};


int main(){
    Player player = Player(Vector2(1, 9));
    std::vector<std::string> ground;
    std::string tes;
    std::ifstream tis("tes.txt");
    while(getline(tis, tes)) {
        ground.push_back(tes);
    }
    int length = ground.size();
    int width = ground[0].size();
    tis.close();
    while(playing) {
        for (int y = 0; y < width; y++) {
            for (int x = 0; x < length; x++) {
                if (Vector2(x, y) == player.location) {
                    std::cout << 'O';
                }
                else {
                    std::cout << ground[y][x];
                }
            }
            std::cout << std::endl;
        }
        std::cout << player.location.x << ", " << player.location.y;
        // std::cout << std::endl << ground[player.location.x + 1][player.location.y];
        int key = getch();
        switch(key) {
            case 92:
                playing = false;
                break;
            case 224:
                int direction = getch();
                switch(direction) {
                    case 72: {
                        char target = ground[player.location.y - 1][player.location.x];
                        if (target == ' ') {
                            player.location.y--;
                        }
                        else if (target == 'F') {
                            playing = false;
                        }
                        break;
                    }
                    case 75: {
                        char target = ground[player.location.y][player.location.x - 1];
                        if (target == ' ') {
                            player.location.x--;
                        }
                        else if (target == 'F') {
                            playing = false;
                        }
                        break;
                    }
                    case 77: {
                        char target = ground[player.location.y][player.location.x + 1];
                        if (target == ' ') {
                            player.location.x++;
                        }
                        else if (target == 'F') {
                            playing = false;
                        }
                        break;
                    }
                    case 80: {
                        char target = ground[player.location.y + 1][player.location.x];
                        if (target == ' ') {
                            player.location.y++;
                        }
                        else if (target == 'F') {
                            playing = false;
                        }
                        break;
                    }
                }
        }
        system("cls");
    }
    std::cout << "YOU WIN!!";
    return 0;
}
/*
72 UP
80 DOWN
77 RIGHT
75 LEFT
*/