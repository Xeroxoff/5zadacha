#include <iostream>
#include <string>

using namespace std;

// класс банкаккаунт
class BankAccount {
protected:
    string account_number;
    string owner_name;
    double balance;

public:
    BankAccount(string account_number, string owner_name, double balance)
        : account_number(account_number), owner_name(owner_name), balance(balance) {}

    // Метод для пополнения счёта
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Пополнено на " << amount << ". Новый баланс: " << balance << endl;
        } else {
            cout << "Сумма пополнения должна быть положительной!" << endl;
        }
    }

    // снятие средств
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Снято " << amount << ". Новый баланс: " << balance << endl;
        } else {
            cout << "Ошибка: Недостаточно средств или неверная сумма для снятия!" << endl;
        }
    }

    // информация о счете (вывод)
    void display_info() const {
        cout << "Номер счёта: " << account_number << endl;
        cout << "Владелец: " << owner_name << endl;
        cout << "Баланс: " << balance << endl;
    }
};

// класс для сберегательных счетов
class SavingsAccount : public BankAccount {
private:
    double interest_rate;  // процентная ставка

public:
    SavingsAccount(string account_number, string owner_name, double balance, double interest_rate)
        : BankAccount(account_number, owner_name, balance), interest_rate(interest_rate) {}

    // начисление процентов
    void apply_interest() {
        double interest = balance * interest_rate / 100;
        balance += interest;
        cout << "Начислены проценты: " << interest << ". Новый баланс: " << balance << endl;
    }

    // отображение ифнормации о счете со сберегательным счетом и процентной ставкой
    void display_info() const {
        BankAccount::display_info();  // вывод информации из класса
        cout << "Процентная ставка: " << interest_rate << "%" << endl;
    }
};

int main() {
    // создание обычного банковского счёта
    BankAccount account("123456789", "Alice", 1000.0);
    cout << "Информация о счёте Alice:" << endl;
    account.display_info();
    account.deposit(500.0);   // Пополнение счёта
    account.withdraw(200.0);  // Снятие средств

    cout << endl;

    // создание сберегательного счёта
    SavingsAccount savings("987654321", "Bob", 2000.0, 5.0);
    cout << "Информация о сберегательном счёте Bob:" << endl;
    savings.display_info();
    savings.deposit(1000.0);   // пополнение счёта
    savings.withdraw(500.0);   // снятие средств
    savings.apply_interest();  // начисление процентов

    return 0;
}