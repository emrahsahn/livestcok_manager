#include "livestock_management.h"
#include <QApplication>
#include <QDebug>
#include <QStringList>
#include <QDesktopServices>
#include <QUrl>

// Describe class implementation
Describe::Describe(QString number, QString type, QString special, QString color_of_earring, 
                   QString color_of_animal, QString whose, QString from_whom, 
                   double price, QString phone_number, QString payment_method)
    : number(number), type(type), special(special), color_of_earring(color_of_earring),
      color_of_animal(color_of_animal), whose(whose), from_whom(from_whom),
      price(price), phone_number(phone_number), payment_method(payment_method), large(2) {
}

QString Describe::toString() const {
    return QString("Hayvanın Numarası:                                                           %1\n"
                  "Hayvanın CİNSİ(Kuzu,keçi,davar gibi):                            %2\n"
                  "Hayvanın ÖZELLİĞİ(Kuyruksuz,kuyruklu...):                 %3\n"
                  "Hayvanın KÜPE RENGi:                                                   %4\n"
                  "Hayvanın RENGİ:                                                              %5\n"
                  "Hayvan KİME AİT:                                                           %6\n"
                  "Hayvan KİMDEN(Kadirden,Mehmetten gibi):                %7\n"
                  "Hayvanın FİYATI(Lütfen sayıyla ve noktayla giriniz):     %8\n"
                  "Hayvan sahibinin TELEFON NUMARASI:                     %9\n"
                  "Nasıl ve Ne Kadar Ödendi:                                               %10\n")
           .arg(number).arg(type).arg(special).arg(color_of_earring)
           .arg(color_of_animal).arg(whose).arg(from_whom)
           .arg(price).arg(phone_number).arg(payment_method);
}

// Library class implementation
Library::Library() {
    createConnect();
}

Library::~Library() {
    interruptConnection();
}

bool Library::createConnect() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("kütüphane.db");
    
    if (!db.open()) {
        qDebug() << "Error: Connection with database failed";
        return false;
    }
    
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS kurbanlık_hesap ("
               "number TEXT, type TEXT, special TEXT, color_of_earring TEXT, "
               "color_of_animal TEXT, whose TEXT, from_whom TEXT, price REAL, "
               "phone_number TEXT, payment_method TEXT)");
    
    return true;
}

void Library::interruptConnection() {
    db.close();
}

QString Library::exhibitCustomer() {
    QSqlQuery query("SELECT * FROM kurbanlık_hesap");
    
    if (query.size() == 0) {
        return "Kaydedilen hiçbir veri yoktur.";
    }
    
    QString result;
    while (query.next()) {
        Describe account(
            query.value(0).toString(),
            query.value(1).toString(),
            query.value(2).toString(),
            query.value(3).toString(),
            query.value(4).toString(),
            query.value(5).toString(),
            query.value(6).toString(),
            query.value(7).toDouble(),
            query.value(8).toString(),
            query.value(9).toString()
        );
        
        result += account.toString() + "\n";
    }
    
    return result;
}

QString Library::queryAnimalNumber(const QString& number) {
    QSqlQuery query;
    query.prepare("SELECT * FROM kurbanlık_hesap WHERE number = ?");
    query.addBindValue(number);
    query.exec();
    
    if (query.size() == 0) {
        return "Kaydedilen hiçbir veri yoktur.";
    }
    
    QString result;
    while (query.next()) {
        Describe account(
            query.value(0).toString(),
            query.value(1).toString(),
            query.value(2).toString(),
            query.value(3).toString(),
            query.value(4).toString(),
            query.value(5).toString(),
            query.value(6).toString(),
            query.value(7).toDouble(),
            query.value(8).toString(),
            query.value(9).toString()
        );
        
        result += account.toString() + "\n";
    }
    
    return result;
}

QString Library::queryAnimalWhose(const QString& whose) {
    QSqlQuery query;
    query.prepare("SELECT * FROM kurbanlık_hesap WHERE LOWER(whose) = ? COLLATE NOCASE");
    query.addBindValue(whose.toLower());
    query.exec();
    
    if (query.size() == 0) {
        return "Böyle bir müşteri bulunmuyor";
    }
    
    QString result;
    while (query.next()) {
        Describe account(
            query.value(0).toString(),
            query.value(1).toString(),
            query.value(2).toString(),
            query.value(3).toString(),
            query.value(4).toString(),
            query.value(5).toString(),
            query.value(6).toString(),
            query.value(7).toDouble(),
            query.value(8).toString(),
            query.value(9).toString()
        );
        
        result += account.toString() + "\n";
    }
    
    return result;
}

QString Library::queryAnimalWhoseAndNumber(const QString& whose, const QString& number) {
    QSqlQuery query;
    query.prepare("SELECT * FROM kurbanlık_hesap WHERE LOWER(whose) = ? AND number = ? COLLATE NOCASE");
    query.addBindValue(whose.toLower());
    query.addBindValue(number);
    query.exec();
    
    if (query.size() == 0) {
        return "Böyle bir kişi ve numara bulunmuyor";
    }
    
    QString result;
    while (query.next()) {
        Describe account(
            query.value(0).toString(),
            query.value(1).toString(),
            query.value(2).toString(),
            query.value(3).toString(),
            query.value(4).toString(),
            query.value(5).toString(),
            query.value(6).toString(),
            query.value(7).toDouble(),
            query.value(8).toString(),
            query.value(9).toString()
        );
        
        result += account.toString() + "\n";
    }
    
    return result;
}

QString Library::queryAnimalType(const QString& type) {
    QSqlQuery query;
    query.prepare("SELECT * FROM kurbanlık_hesap WHERE LOWER(type) = ? COLLATE NOCASE");
    query.addBindValue(type.toLower());
    query.exec();
    
    if (query.size() == 0) {
        return "Böyle bir müşteri bulunmuyor";
    }
    
    QString result;
    while (query.next()) {
        Describe account(
            query.value(0).toString(),
            query.value(1).toString(),
            query.value(2).toString(),
            query.value(3).toString(),
            query.value(4).toString(),
            query.value(5).toString(),
            query.value(6).toString(),
            query.value(7).toDouble(),
            query.value(8).toString(),
            query.value(9).toString()
        );
        
        result += account.toString() + "\n";
    }
    
    return result;
}

QString Library::queryAnimalPhoneNumber(const QString& phone_number) {
    QSqlQuery query;
    query.prepare("SELECT * FROM kurbanlık_hesap WHERE LOWER(phone_number) = ? COLLATE NOCASE");
    query.addBindValue(phone_number);
    query.exec();
    
    if (query.size() == 0) {
        return "Böyle bir müşteri bulunmuyor";
    }
    
    QString result;
    while (query.next()) {
        Describe account(
            query.value(0).toString(),
            query.value(1).toString(),
            query.value(2).toString(),
            query.value(3).toString(),
            query.value(4).toString(),
            query.value(5).toString(),
            query.value(6).toString(),
            query.value(7).toDouble(),
            query.value(8).toString(),
            query.value(9).toString()
        );
        
        result += account.toString() + "\n";
    }
    
    return result;
}

bool Library::add(const Describe& customer) {
    QSqlQuery query;
    query.prepare("INSERT INTO kurbanlık_hesap VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    
    QString new_phone_number = QString("%1 %2 %3 %4")
                              .arg(customer.phone_number.mid(0, 4))
                              .arg(customer.phone_number.mid(4, 3))
                              .arg(customer.phone_number.mid(7, 2))
                              .arg(customer.phone_number.mid(9));
    
    query.addBindValue(customer.number);
    query.addBindValue(customer.type);
    query.addBindValue(customer.special);
    query.addBindValue(customer.color_of_earring);
    query.addBindValue(customer.color_of_animal);
    query.addBindValue(customer.whose);
    query.addBindValue(customer.from_whom);
    query.addBindValue(customer.price);
    query.addBindValue(new_phone_number);
    query.addBindValue(customer.payment_method);
    
    return query.exec();
}

int Library::countData() {
    QSqlQuery query("SELECT COUNT(*) FROM kurbanlık_hesap");
    if (query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

double Library::sumPrice() {
    QSqlQuery query("SELECT SUM(price) FROM kurbanlık_hesap");
    if (query.next()) {
        return query.value(0).toDouble();
    }
    return 0.0;
}

bool Library::upgradeDataNumber(const QString& number_to_update, const QString& new_number) {
    QSqlQuery query;
    query.prepare("UPDATE kurbanlık_hesap SET number = ? WHERE number = ?");
    query.addBindValue(new_number);
    query.addBindValue(number_to_update);
    return query.exec();
}

bool Library::upgradeDataType(const QString& number_to_update, const QString& new_kind) {
    QSqlQuery query;
    query.prepare("UPDATE kurbanlık_hesap SET type = ? WHERE number = ?");
    query.addBindValue(new_kind);
    query.addBindValue(number_to_update);
    return query.exec();
}

bool Library::upgradeDataFeature(const QString& number_to_update, const QString& new_special) {
    QSqlQuery query;
    query.prepare("UPDATE kurbanlık_hesap SET special = ? WHERE number = ?");
    query.addBindValue(new_special);
    query.addBindValue(number_to_update);
    return query.exec();
}

bool Library::upgradeDataColorOfEarring(const QString& number_to_update, const QString& new_color_of_earring) {
    QSqlQuery query;
    query.prepare("UPDATE kurbanlık_hesap SET color_of_earring = ? WHERE number = ?");
    query.addBindValue(new_color_of_earring);
    query.addBindValue(number_to_update);
    return query.exec();
}

bool Library::upgradeDataColorOfAnimal(const QString& number_to_update, const QString& new_color_of_animal) {
    QSqlQuery query;
    query.prepare("UPDATE kurbanlık_hesap SET color_of_animal = ? WHERE number = ?");
    query.addBindValue(new_color_of_animal);
    query.addBindValue(number_to_update);
    return query.exec();
}

bool Library::upgradeDataWhose(const QString& number_to_update, const QString& new_whose) {
    QSqlQuery query;
    query.prepare("UPDATE kurbanlık_hesap SET whose = ? WHERE number = ?");
    query.addBindValue(new_whose);
    query.addBindValue(number_to_update);
    return query.exec();
}

bool Library::upgradeDataFromWhom(const QString& number_to_update, const QString& new_from_whom) {
    QSqlQuery query;
    query.prepare("UPDATE kurbanlık_hesap SET from_whom = ? WHERE number = ?");
    query.addBindValue(new_from_whom);
    query.addBindValue(number_to_update);
    return query.exec();
}

bool Library::upgradeDataPrice(const QString& number_to_update, const QString& new_price) {
    QSqlQuery query;
    query.prepare("UPDATE kurbanlık_hesap SET price = ? WHERE number = ?");
    query.addBindValue(new_price.toDouble());
    query.addBindValue(number_to_update);
    return query.exec();
}

bool Library::upgradeDataPhoneNumber(const QString& number_to_update, const QString& new_phone_number) {
    QSqlQuery query;
    QString formatted_phone = QString("%1 %2 %3 %4")
                             .arg(new_phone_number.mid(0, 4))
                             .arg(new_phone_number.mid(4, 3))
                             .arg(new_phone_number.mid(7, 2))
                             .arg(new_phone_number.mid(9));
                             
    query.prepare("UPDATE kurbanlık_hesap SET phone_number = ? WHERE number = ?");
    query.addBindValue(formatted_phone);
    query.addBindValue(number_to_update);
    return query.exec();
}

bool Library::upgradeDataPaymentMethod(const QString& number_to_update, const QString& new_payment_method) {
    QSqlQuery query;
    query.prepare("UPDATE kurbanlık_hesap SET payment_method = ? WHERE number = ?");
    query.addBindValue(new_payment_method);
    query.addBindValue(number_to_update);
    return query.exec();
}

// LibraryApp implementation
LibraryApp::LibraryApp(QWidget *parent) : QWidget(parent) {
    initUI();
}

LibraryApp::~LibraryApp() {
}

void LibraryApp::initUI() {
    setWindowTitle("Kurbanlık Program");
    setGeometry(0, 0, 1100, 1000);
    
    text_edit = new QTextEdit(this);
    text_edit->setStyleSheet("background-color: rgb(255, 255, 255);"
                           "border-color: rgb(18, 18, 18);"
                           "color: rgb(0, 0, 0);"
                           "font: bold 11pt \"Times New Roman\";");
    text_edit->setGeometry(0, 0, 800, 1000);
    
    button_show_customers = new QPushButton("Müşterileri Göster", this);
    button_show_customers->setGeometry(850, 10, 230, 30);
    connect(button_show_customers, &QPushButton::clicked, this, &LibraryApp::showCustomers);
    
    button_query_customers = new QPushButton("Müşterileri Sorgula", this);
    button_query_customers->setGeometry(850, 60, 230, 30);
    connect(button_query_customers, &QPushButton::clicked, this, &LibraryApp::queryCustomers);
    
    button_add_customer = new QPushButton("Müşteri Ekle", this);
    button_add_customer->setGeometry(850, 110, 230, 30);
    connect(button_add_customer, &QPushButton::clicked, this, &LibraryApp::addCustomer);
    
    button_count_customers = new QPushButton("Kayıtlı Olan Müşteri Sayısı", this);
    button_count_customers->setGeometry(850, 160, 230, 30);
    connect(button_count_customers, &QPushButton::clicked, this, &LibraryApp::countCustomers);
    
    button_sum_price = new QPushButton("Kayıtlı Olan Müşterilerden Toplam ALACAK", this);
    button_sum_price->setGeometry(850, 210, 230, 30);
    connect(button_sum_price, &QPushButton::clicked, this, &LibraryApp::sumPrice);
    
    button_update_customer = new QPushButton("Düzeltilmek İstenen Müşteri Kaydı", this);
    button_update_customer->setGeometry(850, 260, 230, 30);
    connect(button_update_customer, &QPushButton::clicked, this, &LibraryApp::updateCustomer);
    
    button_quit = new QPushButton("Çıkış", this);
    button_quit->setGeometry(850, 310, 230, 30);
    connect(button_quit, &QPushButton::clicked, this, &LibraryApp::quit);
    
    button_person_who_does = new QPushButton("!! Emrah ŞAHİN !!", this);
    button_person_who_does->setGeometry(850, 950, 230, 30);
    connect(button_person_who_does, &QPushButton::clicked, this, &LibraryApp::personWhoDoes);
}

void LibraryApp::personWhoDoes() {
    QDialog* my_info_window = new QDialog(this);
    my_info_window->setWindowTitle("Yapan Kişi Bilgileri");
    my_info_window->setGeometry(100, 100, 200, 200);
    
    QVBoxLayout* layout = new QVBoxLayout();
    
    QLabel* information = new QLabel();
    information->setText("<html>Kişi Bilgileri<br><br>"
                       "Adı: Emrah ŞAHİN <br>"
                       "E-posta: <a href='mailto:sahinemrah3344@gmail.com'>sahinemrah3344@gmail.com</a><br>"
                       "Github:<a href='https://github.com/emrahsahn'> WebSite </a><br>"
                       "Telefon Numarası:<a href='tel:+905380874885'>0538-087-4885</a><br>"
                       "Linkedln:<a href='www.linkedin.com/in/emrah-şahin-788799253'>WebSite</a></html>");
    
    information->setGeometry(0, 0, 50, 100);
    information->setOpenExternalLinks(true);
    layout->addWidget(information);
    
    my_info_window->setLayout(layout);
    my_info_window->exec();
}

void LibraryApp::showCustomers() {
    QString result = library.exhibitCustomer();
    text_edit->clear();
    text_edit->append(result);
}

void LibraryApp::queryCustomers() {
    QStringList options;
    options << "Seçiniz" << "Müşterinin hayvan numarası ile sorgulama:"
            << "Hayvanın kime ait olduğu ile sorgulama:"
            << "Hayvanın kime ait olduğu ve numarası ile sorgulama:"
            << "Hayvanın türü ile sorgulama:"
            << "Hayvan sahibinin telefon numarası ile sorgulama:";
    
    bool ok;
    QString selected_option = QInputDialog::getItem(this, "Müşteri Sorgulama",
                                                 "Sorgulama Yöntemi Seçin:", options, 0, false, &ok);
    
    if (ok && !selected_option.isEmpty()) {
        if (selected_option == "Seçiniz") {
            return;
        }
        else if (selected_option == "Müşterinin hayvan numarası ile sorgulama:") {
            QString text = QInputDialog::getText(this, "Müşteri Sorgula",
                                              "Müşterinin hayvan numarasını girin:", QLineEdit::Normal, "", &ok);
            if (ok && !text.isEmpty()) {
                QString result = library.queryAnimalNumber(text);
                text_edit->clear();
                text_edit->append(result);
            }
        }
        else if (selected_option == "Hayvanın kime ait olduğu ile sorgulama:") {
            QString text = QInputDialog::getText(this, "Müşteri Sorgula",
                                              "Hayvanının sahibinin ismini girin:", QLineEdit::Normal, "", &ok);
            if (ok && !text.isEmpty()) {
                QString result = library.queryAnimalWhose(text);
                text_edit->clear();
                text_edit->append(result);
            }
        }
        else if (selected_option == "Hayvanın kime ait olduğu ve numarası ile sorgulama:") {
            QString text_number = QInputDialog::getText(this, "Müşteri Sorgula",
                                                     "Hayvanın numarasını girin:", QLineEdit::Normal, "", &ok);
            if (!ok) return;
            
            QString text_whose = QInputDialog::getText(this, "Müşteri Sorgula",
                                                    "Hayvan sahibinin ismini girin:", QLineEdit::Normal, "", &ok);
            
            if (ok && (!text_number.isEmpty() || !text_whose.isEmpty())) {
                QString result = library.queryAnimalWhoseAndNumber(text_whose, text_number);
                text_edit->clear();
                text_edit->append(result);
            }
        }
        else if (selected_option == "Hayvanın türü ile sorgulama:") {
            QString text = QInputDialog::getText(this, "Müşteri Sorgula",
                                              "Hayvanının türünü girin:", QLineEdit::Normal, "", &ok);
            if (ok && !text.isEmpty()) {
                QString result = library.queryAnimalType(text);
                text_edit->clear();
                text_edit->append(result);
            }
        }
        else if (selected_option == "Hayvan sahibinin telefon numarası ile sorgulama:") {
            QString text = QInputDialog::getText(this, "Müşteri Sorgula",
                                              "Hayvan sahibinin telefon numarasını girin:", QLineEdit::Normal, "", &ok);
            if (ok && !text.isEmpty()) {
                text = text.trimmed();
                text = QString("%1 %2 %3 %4")
                      .arg(text.mid(0, 4))
                      .arg(text.mid(4, 3))
                      .arg(text.mid(7, 2))
                      .arg(text.mid(9));
                
                QString result = library.queryAnimalPhoneNumber(text);
                text_edit->clear();
                text_edit->append(result);
            }
        }
    }
}

void LibraryApp::addCustomer() {
    QStringList customer_data;
    QStringList fields = {"numara", "cins", "özellik", "küpe rengi", "renk", "kime ait", "kimden", "fiyat", "telefon numarası", "ödeme yöntemi"};
    
    bool ok;
    for (const QString& field : fields) {
        QString text = QInputDialog::getText(this, "Müşteri Ekle",
                                          QString("Hayvanın %1 girin:").arg(field),
                                          QLineEdit::Normal, "", &ok);
        if (ok && !text.isEmpty()) {
            customer_data << text;
        } else {
            text_edit->clear();
            text_edit->append("Hatalı giriş. Müşteri eklenemedi.");
            return;
        }
    }
    
    try {
        Describe customer(
            customer_data[0],
            customer_data[1],
            customer_data[2],
            customer_data[3],
            customer_data[4],
            customer_data[5],
            customer_data[6],
            customer_data[7].toDouble(),
            customer_data[8],
            customer_data[9]
        );
        
        if (library.add(customer)) {
            text_edit->clear();
            text_edit->append("Müşteri başarıyla eklendi.");
        } else {
            text_edit->clear();
            text_edit->append("Müşteri eklenirken bir hata oluştu.");
        }
    } catch (...) {
        text_edit->clear();
        text_edit->append("Beklenmeyen bir hata oluştu. Müşteri eklenemedi.");
    }
}

void LibraryApp::countCustomers() {
    int count = library.countData();
    text_edit->clear();
    text_edit->append(QString("Kütüphanemizdeki kayıtlı müşteri sayısı sayısı: %1").arg(count));
}

void LibraryApp::sumPrice() {
    double total_price = library.sumPrice();
    text_edit->clear();
    text_edit->append(QString("Kütüphanemizdeki kayıtlı olan müşterilerden toplam ALINACAK: %1").arg(total_price));
}

void LibraryApp::updateCustomer() {
    QStringList options;
    options << "Verinin hangi kısmını düzeltmek istiyorsunuz" 
            << "Hayvanın numarası için düzenleme:"
            << "Hayvanın cinsi için düzenleme:"
            << "Hayvanın özelliği için düzenleme:"
            << "Hayvanın Küpe Rengi için düzenleme:"
            << "Hayvanın rengi için düzenleme:"
            << "Hayvanın kime ait olduğunu değiştirmek için düzenleme:"
            << "Hayvanın kimden olduğunu değiştirmek için düzenleme:"
            << "Hayvanın fiyatı için düzenleme:"
            << "Hayvanın sahibinin telefon numarasını değiştirmek için düzenleme:"
            << "Ödeme Yöntemi ve ne kadar ödendi:";
    
    bool ok;
    QString selected_option = QInputDialog::getItem(this, "Müşteri Hataları Düzenleme",
                                                 "Düzenleme Yöntemi Seçin:", options, 0, false, &ok);
    
    if (ok && !selected_option.isEmpty()) {
        if (selected_option == "Seçiniz") {
            return;
        }
        else if (selected_option == "Hayvanın numarası için düzenleme:") {
            QString text = QInputDialog::getText(this, "Müşteri Güncelle",
                                              "Hayvanın yeni numarasını girin:(eski numara,yeni numara)şeklinde giriniz",
                                              QLineEdit::Normal, "", &ok);
            if (ok && !text.isEmpty()) {
                QStringList info = text.split(',');
                if (info.length() == 2) {
                    if (library.upgradeDataNumber(info[0], info[1])) {
                        text_edit->clear();
                        text_edit->append("Müşteri başarıyla güncellendi.");
                    } else {
                        text_edit->clear();
                        text_edit->append("Güncelleme sırasında bir hata oluştu.");
                    }
                } else {
                    text_edit->clear();
                    text_edit->append("Hatalı giriş. Müşteri güncellenemedi.");
                }
            }
        }
        else if (selected_option == "Hayvanın cinsi için düzenleme:") {
            QString text = QInputDialog::getText(this, "Müşteri Güncelle",
                                              "Hayvanın cinsini girin:(numara, yeni cins) şeklinde giriniz",
                                              QLineEdit::Normal, "", &ok);
            if (ok && !text.isEmpty()) {
                QStringList info = text.split(',');
                if (info.length() == 2) {
                    if (library.upgradeDataType(info[0].trimmed(), info[1].trimmed())) {
                        text_edit->clear();
                        text_edit->append("Müşteri başarıyla güncellendi.");
                    } else {
                        text_edit->clear();
                        text_edit->append("Güncelleme sırasında bir hata oluştu.");
                    }
                } else {
                    text_edit->clear();
                    text_edit->append("Hatalı giriş. Müşteri güncellenemedi.");
                }
            }
        }
        // Similar implementation for other update options
        // ...
        else if (selected_option == "Ödeme Yöntemi ve ne kadar ödendi:") {
            QString text_number = QInputDialog::getText(this, "Müşteri Sorgula",
                                                     "Hayvanın numarasını girin:",
                                                     QLineEdit::Normal, "", &ok);
            if (!ok) return;
            
            QString text_payment_method = QInputDialog::getText(this, "Müşteri Sorgula",
                                                            "Ödeme şekli ve ne kadar ödendiğini girin:",
                                                            QLineEdit::Normal, "", &ok);
            
            if (ok && (!text_number.isEmpty() || !text_payment_method.isEmpty())) {
                if (library.upgradeDataPaymentMethod(text_number, text_payment_method)) {
                    text_edit->clear();
                    text_edit->append("Müşteri başarıyla güncellendi.\n");
                } else {
                    text_edit->clear();
                    text_edit->append("Güncelleme sırasında bir hata oluştu.");
                }
            } else {
                text_edit->clear();
                text_edit->append("Hatalı giriş. Müşteri güncellenemedi.\n");
            }
        }
    }
}

void LibraryApp::quit() {
    close();
}
