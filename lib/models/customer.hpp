#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <QObject>
#include <QString>

#include "city.hpp"

class Customer : public QObject
{
    Q_OBJECT

private:
    int m_Id;
    QString m_tc;
    QString m_name;
    QString m_surname;
    QString m_phone;
    City *m_city;
    QString m_address;

public:
    explicit Customer(QObject *parent = 0);

    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString tc READ getTc WRITE setTc NOTIFY tcChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString surname READ getSurname WRITE setSurname NOTIFY surnameChanged)
    Q_PROPERTY(QString phone READ getPhone WRITE setPhone NOTIFY phoneChanged)
    Q_PROPERTY(City* city READ getCity WRITE setCity NOTIFY cityChanged)
    Q_PROPERTY(QString address READ getAddress WRITE setAddress NOTIFY addressChanged)

    int getId() const;
    QString getTc() const;
    QString getName() const;
    QString getSurname() const;
    QString getPhone() const;
    City *getCity() const;
    QString getAddress() const;

signals:
    void idChanged(int newId);
    void tcChanged(QString newTc);
    void nameChanged(QString newName);
    void surnameChanged(QString newSurname);
    void phoneChanged(QString newPhone);
    void cityChanged(City *newCity);
    void addressChanged(QString newAddress);

public slots:
    void setId(int value);
    void setTc(const QString &value);
    void setName(const QString &value);
    void setSurname(const QString &value);
    void setPhone(const QString &value);
    void setCity(City *city);
    void setAddress(const QString &value);
};

#endif // CUSTOMER_HPP
