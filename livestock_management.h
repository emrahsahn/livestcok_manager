#ifndef LIVESTOCK_MANAGEMENT_H
#define LIVESTOCK_MANAGEMENT_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QString>
#include <QList>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

// Animal description class
class Describe {
public:
    Describe(QString number, QString type, QString special, QString color_of_earring, 
             QString color_of_animal, QString whose, QString from_whom, 
             double price, QString phone_number, QString payment_method);
    
    QString toString() const;

    QString number;
    QString type;
    QString special;
    QString color_of_earring;
    QString color_of_animal;
    QString whose;
    QString from_whom;
    double price;
    QString phone_number;
    QString payment_method;
    int large;
};

// Database management class
class Library {
public:
    Library();
    ~Library();
    
    bool createConnect();
    void interruptConnection();
    
    QString exhibitCustomer();
    QString queryAnimalNumber(const QString& number);
    QString queryAnimalWhose(const QString& whose);
    QString queryAnimalWhoseAndNumber(const QString& whose, const QString& number);
    QString queryAnimalType(const QString& type);
    QString queryAnimalPhoneNumber(const QString& phone_number);
    
    bool add(const Describe& customer);
    int countData();
    double sumPrice();
    
    bool upgradeDataNumber(const QString& number_to_update, const QString& new_number);
    bool upgradeDataType(const QString& number_to_update, const QString& new_kind);
    bool upgradeDataFeature(const QString& number_to_update, const QString& new_special);
    bool upgradeDataColorOfEarring(const QString& number_to_update, const QString& new_color_of_earring);
    bool upgradeDataColorOfAnimal(const QString& number_to_update, const QString& new_color_of_animal);
    bool upgradeDataWhose(const QString& number_to_update, const QString& new_whose);
    bool upgradeDataFromWhom(const QString& number_to_update, const QString& new_from_whom);
    bool upgradeDataPrice(const QString& number_to_update, const QString& new_price);
    bool upgradeDataPhoneNumber(const QString& number_to_update, const QString& new_phone_number);
    bool upgradeDataPaymentMethod(const QString& number_to_update, const QString& new_payment_method);

private:
    QSqlDatabase db;
};

// GUI Application class
class LibraryApp : public QWidget {
    Q_OBJECT

public:
    LibraryApp(QWidget *parent = nullptr);
    ~LibraryApp();

private slots:
    void showCustomers();
    void queryCustomers();
    void addCustomer();
    void countCustomers();
    void sumPrice();
    void updateCustomer();
    void personWhoDoes();
    void quit();

private:
    void initUI();
    
    QTextEdit *text_edit;
    QPushButton *button_show_customers;
    QPushButton *button_query_customers;
    QPushButton *button_add_customer;
    QPushButton *button_count_customers;
    QPushButton *button_sum_price;
    QPushButton *button_update_customer;
    QPushButton *button_quit;
    QPushButton *button_person_who_does;
    
    Library library;
};

#endif // LIVESTOCK_MANAGEMENT_H
