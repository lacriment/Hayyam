#ifndef DISTANCE_HPP
#define DISTANCE_HPP

#include <QObject>

#include "office.hpp"

class Distance : public QObject
{
    Q_OBJECT

private:
    int m_id;
    Office* m_firstOffice;
    Office* m_secondOffice;
    double m_value;

public:
    explicit Distance(QObject *parent = 0);

    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(Office* firstOffice READ getFirstOffice WRITE setFirstOffice NOTIFY firstOfficeChanged)
    Q_PROPERTY(Office* secondOffice READ getSecondOffice WRITE setSecondOffice NOTIFY secondOfficeChanged)
    Q_PROPERTY(double value READ getValue WRITE setValue NOTIFY valueChanged)

    int getId() const;
    Office *getFirstOffice() const;
    Office *getSecondOffice() const;
    double getValue() const;

signals:
    void firstOfficeChanged(Office *newFirstOffice);
    void idChanged(int newId);
    void secondOfficeChanged(Office *newSecondOffice);
    void valueChanged(double newValue);

public slots:
    void setFirstOffice(Office *firstOffice);
    void setId(int id);
    void setSecondOffice(Office *secondOffice);
    void setValue(double value);
};

#endif // DISTANCE_HPP
