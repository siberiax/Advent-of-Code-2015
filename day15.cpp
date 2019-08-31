#include <iostream>
#include <vector>

using namespace std;

class Ingredient
{
    public:
    int capacity;
    int durability;
    int flavor;
    int texture;
    int calories;
};

int main(int argc, char** argv){

    Ingredient sprinkles;
    Ingredient pb;
    Ingredient frosting;
    Ingredient sugar;

    sprinkles.capacity = 5;
    sprinkles.durability = -1;
    sprinkles.flavor = 0;
    sprinkles.texture = 0;
    sprinkles.calories = 5;

    pb.capacity = -1;
    pb.durability = 3;
    pb.flavor = 0;
    pb.texture = 0;
    pb.calories = 1;

    frosting.capacity = 0;
    frosting.durability = -1;
    frosting.flavor = 4;
    frosting.texture = 0;
    frosting.calories = 6;

    sugar.capacity = -1;
    sugar.durability = 0;
    sugar.flavor = 0;
    sugar.texture = 2;
    sugar.calories = 8;

    int total = 100;
    int highest = 0;
    for (int i = 0; i <= total; i++){
        for (int j = 0; j <= total - i; j++){
            for (int k = 0; k <= total - i - j; k++){
                int l = total - i - j - k;
                int capacity = sprinkles.capacity * i + pb.capacity * j + frosting.capacity * k + sugar.capacity * l;
                int durability = sprinkles.durability * i + pb.durability * j + frosting.durability * k + sugar.durability * l;
                int flavor = sprinkles.flavor * i + pb.flavor * j + frosting.flavor * k + sugar.flavor * l;
                int texture = sprinkles.texture * i + pb.texture * j + frosting.texture * k + sugar.texture * l;
                int calories = sprinkles.calories * i + pb.calories * j + frosting.calories * k + sugar.calories * l;

                if (calories == 500 && capacity > 0 && durability > 0 && flavor > 0 && texture > 0){
                    int curr_total = capacity * durability * flavor  * texture;
                    if (curr_total > highest){
                        highest = curr_total;
                    }
                }
            }
        }
    }
    cout << highest << "\n";
}
