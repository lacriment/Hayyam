#ifndef SHIPMENT_HPP
#define SHIPMENT_HPP

#include <QObject>
#include <QString>

#include "customer.hpp"
#include "office.hpp"

class Shipment : public QObject
{
    Q_OBJECT

private:
    int m_id;
    int m_length;
    int m_width;
    int m_height;
    int m_weight;
    Customer *m_sendingCustomer;
    Customer *m_receivingCustomer;
    int m_paymentType;
    double m_amount;
    int m_status;
    Office *m_sendingOffice;
    Office *m_receivingOffice;

public:
    explicit Shipment(QObject *parent = 0);

    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(int length READ getLength WRITE setLength NOTIFY lengthChanged)
    Q_PROPERTY(int width READ getWidth WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ getHeight WRITE setHeight NOTIFY heightChanged)
    Q_PROPERTY(int weight READ getWeight WRITE setWeight NOTIFY weightChanged)
    Q_PROPERTY(Customer* sendingCustomer READ getSendingCustomer WRITE setSendingCustomer NOTIFY sendingCustomerChanged)
    Q_PROPERTY(Customer* receivingCustomer READ getReceivingCustomer WRITE setReceivingCustomer NOTIFY receivingCustomerChanged)
    Q_PROPERTY(int paymentType READ getPaymentType WRITE setPaymentType NOTIFY paymentTypeChanged)
    Q_PROPERTY(double amount READ getAmount WRITE setAmount NOTIFY amountChanged)
    Q_PROPERTY(int status READ getStatus WRITE setStatus NOTIFY statusChanged)
    Q_PROPERTY(Office* sendingOffice READ getSendingOffice WRITE setSendingOffice NOTIFY sendingOfficeChanged)
    Q_PROPERTY(Office* receivingOffice READ getReceivingOffice WRITE setReceivingOffice NOTIFY receivingOfficeChanged)

    int getId() const;
    int getLength() const;
    int getWidth() const;
    int getHeight() const;
    int getWeight() const;
    Customer *getSendingCustomer() const;
    Customer *getReceivingCustomer() const;
    int getPaymentType() const;
    double getAmount() const;
    int getStatus() const;
    Office *getSendingOffice() const;
    Office *getReceivingOffice() const;

signals:
    void idChanged(int newId);
    void lengthChanged(int newLength);
    void widthChanged(int newWidth);
    void heightChanged(int newHeight);
    void weightChanged(int newWeight);
    void sendingCustomerChanged(Customer *newSendingCustomer);
    void receivingCustomerChanged(Customer *newReceivingCustomer);
    void paymentTypeChanged(int newPaymentType);
    void amountChanged(double newAmount);
    void statusChanged(int newStatus);
    void sendingOfficeChanged(Office *newSendingOffice);
    void receivingOfficeChanged(Office *newReceivingOffice);

public slots:
    void setId(int id);
    void setLength(int length);
    void setWidth(int width);
    void setHeight(int height);
    void setWeight(int weight);
    void setSendingCustomer(Customer *sendingCustomer);
    void setReceivingCustomer(Customer *receivingCustomer);
    void setPaymentType(int paymentType);
    void setAmount(double amount);
    void setStatus(int status);
    void setSendingOffice(Office *sendingOffice);
    void setReceivingOffice(Office *receivingOffice);
};

#endif // SHIPMENT_HPP
