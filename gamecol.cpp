#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Класс персонажа
class Character {
protected:
    string name;
    int health;

public:
    Character(const string& name, int health) : name(name), health(health) {}

    // Проверка на живого персонажа
    bool isAlive() const {
        return health > 0;
    }

    // Получение урона
    void takeDamage(int damage) {
        health -= damage;
        if (health < 0)
            health = 0;
    }

    // Получение текущего здоровья
    int getHealth() const {
        return health;
    }

    // Получение имени персонажа
    const string& getName() const {
        return name;
    }
};

// Класс игрока, наследуется от класса Character
class Player : public Character {
public:
    Player(const string& name) : Character(name, 100) {}

    // Метод для атаки врага
    void attack(Character& enemy) {
        int damage = rand() % 21 + 10; // Рандомный урон от 10 до 30
        enemy.takeDamage(damage);
        cout << name << " атакует " << enemy.getName() << " и наносит " << damage << " урона!\n";
    }
};

// Класс врага, наследуется от класса Character
class Enemy : public Character {
public:
    Enemy() : Character("Враг", 100) {}

    // Метод для атаки игрока
    void attack(Character& player) {
        int damage = rand() % 16 + 5; // Рандомный урон от 5 до 20
        player.takeDamage(damage);
        cout << "Враг атакует " << player.getName() << " и наносит " << damage << " урона!\n";
    }
};

// Функция для очистки экрана
void clearScreen() {
    cout << string(100, '\n');
}

// Функция для вывода текущего здоровья игрока и врага
void printHealth(const Player& player, const Enemy& enemy) {
    cout << "Здоровье " << player.getName() << ": " << player.getHealth() << endl;
    cout << "Здоровье " << enemy.getName() << ": " << enemy.getHealth() << endl;
}

int main() {

    setlocale(LC_ALL, "ru");

    srand(time(0)); // Инициализация генератора случайных чисел

    string playerName;
    cout << "Добро пожаловать в игру!\n";
    cout << "Введите имя персонажа: ";
    cin >> playerName;

    Player player(playerName);
    Enemy enemy;

    clearScreen();

    cout << "Привет, " << playerName << "!\n";
    cout << "Ты находишься в лесу, и на тебя напал враг.\n";

    // Игровой цикл
    while (player.isAlive() && enemy.isAlive()) {
        char choice;
        cout << "Выбери действие:\n";
        cout << "1. Атаковать\n";
        cout << "2. Попытаться убежать\n";
        cin >> choice;

        clearScreen();

        switch (choice) {
        case '1':
            player.attack(enemy);
            if (!enemy.isAlive())
                cout << "Поздравляем! Вы победили врага!\n";
            else
                enemy.attack(player);
            break;
        case '2':
            cout << "Вы попытались убежать, но враг атаковал вас!\n";
            enemy.attack(player);
            break;
        default:
            cout << "Неправильный ввод. Попробуйте еще раз.\n";
            break;
        }

        printHealth(player, enemy);
        cout << endl;
    }

    // Вывод результата игры
    if (!player.isAlive())
        cout << "К сожалению, вы проиграли.\n";
    else
        cout << "Игра завершена. Вы победили!\n";

    return 0;
}
