#include<string>
#include<iostream>
#include<ctime>

using namespace std;

struct Student {
    string name;
    int hp;
    int magical_burst;
    int normal_attack;
    int critical_chance;
    int heal;

    Student() : name(""), hp(0), magical_burst(0), normal_attack(0), critical_chance(0), heal(0) {
    }

    Student(string name, int hp = 100, int magical_burst = 20, int normal_attack = 10, int heal = 5,
            int critical_chance = 10) : name(name), hp(hp), magical_burst(magical_burst), normal_attack(normal_attack),
                                        heal(heal), critical_chance(critical_chance) {
    }

    Student(const Student &student) : name(student.name),
                                      hp(student.hp),
                                      magical_burst(student.magical_burst),
                                      normal_attack(student.normal_attack),
                                      heal(student.heal),
                                      critical_chance(student.critical_chance) {
    }

    ~Student() {
    }

    bool hp_Works() {
        return (50 > hp);
    }

    bool critical_chanceWorks() {
        return (rand() % 100 < critical_chance);
    }

    bool isDead() {
        return (hp <= 0);
    }

    void apply_heal() {
        int new_hp = hp + heal;
        if (new_hp > 100) {
            hp = 100;
        }
        cout << "\t" << name << " healed for " << heal << " HP! [" << hp << "]\n";
    }

    void get_normal_attack(int normal_attack) {
        if (hp_Works()) {
            normal_attack /= 2;
            cout << "\t" << name << " HP WORKS FOR GETTING DAMAGE\n";
        }
        hp -= normal_attack;
        if (hp < 0) {
            hp = 0;
        }
    }

    int make_normal_attack() {
        if (hp_Works()) {
            cout << "\t" << name << " HP WORKS FOR MAKING DAMAGE\n";
            return normal_attack;
        }
    }

    void get_magical_burst(int magical_burst) {
        if (critical_chanceWorks()) {
            magical_burst /= 4;
            cout << "\t" << name << " CRITICAL CHANCE WORKS FOR GETTING DAMAGE\n";
        }
        hp -= magical_burst;
        if (hp < 0) {
            hp = 0;
        }
    }

    int make_magical_burst() {
        if (critical_chanceWorks()) {
            cout << "\t" << name << " CRITICAL CHANCE WORKS FOR MAKING DAMAGE\n";
            return magical_burst * 2;
        }
        apply_heal();
        return magical_burst;
    }

    void print() {
        cout << name << " [" << hp << "] (";
        cout << "critical damage=" << critical_chance << ";";
        cout << "normal attack=" << normal_attack << ";";
        cout << "magical burst=" << magical_burst << ")\n";
    }
};

void battle(Student &st1, Student &st2) {
    int round = 1;
    while (!(st1.isDead() || st2.isDead())) {
        cout << "\t\tROUND " << round++ << "\n";
        st1.print();
        cout << "versus\n";
        st2.print();
        st1.get_normal_attack(st2.make_normal_attack());
        st1.get_magical_burst(st2.make_magical_burst());
        if (st1.isDead()) break;
        st2.get_normal_attack(st1.make_normal_attack());
        st2.get_magical_burst(st1.make_magical_burst());
    }
    if (st1.isDead() && st2.isDead()) {
        cout << "DRAW\n";
    } else {
        cout << (st1.isDead() ? st2.name : st1.name) << " wins\n";
    }
}

Student createRandomStudent(int id) {
    string name = "Student_" + to_string(id);
    int hp = rand() % 71 + 30;
    int magical_burst = rand() % 30 + 20;
    int normal_attack = rand() % 20 + 10;
    int heal = rand() % 10 + 5;
    int critical_damage = rand() % 20 + 10;

    return Student(name, hp, magical_burst, normal_attack, heal, critical_damage);
}

void sortStudentsByMagicalBurst(Student students[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (students[j].magical_burst < students[j + 1].magical_burst) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(0));
    Student students[10];
    for (int i = 0; i < 10; ++i) {
        students[i] = createRandomStudent(i + 1);
    }

    sortStudentsByMagicalBurst(students, 10);

    cout << "Список студентов (отсортированных по Magical Burst):\n";
    for (int i = 0; i < 10; ++i) {
        students[i].print();
    }

    cout << "\n Начинаем квалификацию!\n";
    Student winners[5];
    for (int i = 0; i < 5; ++i) {
        cout << "\n Бой " << (i + 1) << ":\n";
        battle(students[i], students[9 - i]);
        winners[i] = students[i].isDead() ? students[9 - i] : students[i];
    }

    cout << "\n Победители квалификации:\n";
    for (int i = 0; i < 5; ++i) {
        winners[i].print();
    }

    cout << "\n Начинаем полуфинал!\n";
    sortStudentsByMagicalBurst(winners, 5);

    Student finalist = winners[0];
    cout << finalist.name << " проходит в финал автоматически!\n";

    Student semiFinalWinners[2];
    for (int i = 1; i < 4; i += 2) {
        cout << "\n Полуфинальный бой " << ((i + 1) / 2) << ":\n";
        battle(winners[i], winners[i + 1]);
        semiFinalWinners[(i - 1) / 2] = winners[i].isDead() ? winners[i + 1] : winners[i];
    }

    cout << "\n Начинаем финал!\n";
    cout << "Финалисты:\n";
    finalist.print();
    semiFinalWinners[0].print();
    semiFinalWinners[1].print();

    cout << "\n Бой между полуфиналистами:\n";
    battle(semiFinalWinners[0], semiFinalWinners[1]);
    Student finalOpponent = semiFinalWinners[0].isDead() ? semiFinalWinners[1] : semiFinalWinners[0];

    cout << "\n Финальный бой:\n";
    battle(finalist, finalOpponent);

    return 0;
}
