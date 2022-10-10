#include <string>
#include <iostream>
#include <vector>
#include "Weapon.h"
#include "Character.h"
#include "Attacks.h"
#include "Creature.h"
#include "Item.h"
#include"Monster.h"

using namespace std;

int main()
{
    /*Weapon weapon1 = Weapon("Sword1", Sword, 10, 50, 100, 1);
    Weapon weapon2 = Weapon("Sword2", Sword, 5, 25, 50, 1);

    // weapon1.ToString();

    //Before modifications for creature

    Character character1 = Character("Fried", "Frid");
    Character character2 = Character("Vahn", "FF", "Hello", 200, 100, weapon1, Human, Paladin);

    // character2.Introduce();

    vector<Weapon*> stock;
    stock.push_back(&weapon2);

    Merchant merchant1 = Merchant("Welcome RE4");
    Merchant merchant2 = Merchant("David", "Library", "What are you buying ?", "Some papppeeeeer", 500);
    Merchant merchant3 = Merchant("Dave", "Magic", "Smithy", "Hammer", 250, stock);

    // character1.UseWeapon(&weapon1, &character2);

    // Buy weapon
    /*
    character1.Buy(&weapon2, &merchant3);
    character2.Buy(&weapon2, &merchant3);
    cout << "nb stock : " << merchant3.GetNbWeapon() << endl;

    character1.Introduce();
    character2.Introduce();
    

    // Sell weapon
    character1.Sell(&merchant3);
    character2.Sell(&merchant1);
    cout << "nb stock : " << merchant1.GetNbWeapon() << endl;
    character2.Introduce();*/


    // SET UP CHARA, WEAPONS AND ATTACKS

    Weapon weapon1 = Weapon("Buster Sword", Sword, 100, 1000, 5000, 1);
    Weapon weapon2 = Weapon("Black Materia", Staff, 1, 9999, 10000, 1);
    Weapon weapon3 = Weapon("Lava Tear", Staff, 1, 100, 200, 1);



    Attacks attacks1 = Attacks("OmniSlash", &weapon1 ,25, Slashing, 2);
    Attacks attacks2 = Attacks("Meteor", &weapon2, 100, Burning, 5);
    Attacks attacks3 = Attacks("Fire", &weapon3, 50, Burning, 3);

    //Creature creature1 = Creature("Cloud", "Ancient soldier", 15000.0f, &attacks1, 15.0f);
    Creature creature1 = Creature("Cloud", "Ancient soldier", 15000.0f, 15.0f);
    Creature creature2 = Creature("Sephiroth", "One Angel-Wing", 50000.0f, 10.0f);

    Item item1 = Item("Elixir", "Restore all HP & MP", 0.5f);
    Item item2 = Item("Amulet", "Protect from magics fire", 2.0f);

    Monster monster1 = Monster("Bamboo", "A explosive monster", 1000.0f, 5.0f);
    Monster monster2 = Monster("Bahamut", "A Eon or a God for the mortals", 99999.9f, 20.0f);

    monster1.AddAttack(&attacks3);
    monster2.AddAttack(&attacks2);

    monster1.AddItem(&item2);
    monster2.AddItem(&item1);



}
